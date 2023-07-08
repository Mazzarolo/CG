#include "Cylinder.h"

Cylinder::Cylinder(int orientation, float radiusMultiplier, float heightMultiplier)
{
    float ang = 0;
    float inc = 2 * PI / DIM;

    for (int i = 0; i <= DIM; i++)
    {
        for (int j = 0; j <= DIM; j++)
        {
            if(orientation == 0)
            {
                mat[i][j].x = heightMultiplier * 2 * i / (float)DIM - 1;
                mat[i][j].y = cos(ang) * radiusMultiplier;
                mat[i][j].z = sin(ang) * radiusMultiplier;
            }
            else if(orientation == 1)
            {
                mat[i][j].x = cos(ang) * radiusMultiplier;
                mat[i][j].y = heightMultiplier * 2 * i / (float)DIM - 1;
                mat[i][j].z = sin(ang) * radiusMultiplier;
            }
            else if(orientation == 2)
            {
                mat[i][j].x = cos(ang) * radiusMultiplier;
                mat[i][j].y = sin(ang) * radiusMultiplier;
                mat[i][j].z = heightMultiplier * 2 * j / (float)DIM - 1;
            }
            ang += inc;
        }
    }

    // copy the matrix to the auxiliar matrix
    for (int i = 0; i <= DIM; i++)
    {
        for (int j = 0; j <= DIM; j++)
        {
            transf[i][j] = mat[i][j];
        }
    }
}

Point Cylinder::rotateX(Point p)
{
    Point resp;
    ang += 0.000001;
    if(ang > 2 * PI)
        ang = 0;

    resp.x = p.x;
    resp.y = cos(ang) * p.y - sin(ang) * p.z;
    resp.z = sin(ang) * p.y + cos(ang) * p.z;

    return resp;
}

Point Cylinder::rotateX(Point p, float angle)
{
    Point resp;

    resp.x = p.x;
    resp.y = cos(angle) * p.y - sin(angle) * p.z;
    resp.z = sin(angle) * p.y + cos(angle) * p.z;

    return resp;
}

void Cylinder::rotateCylinderX(float angle)
{
    for (int x = 0; x <= DIM; x++)
        for (int z = 0; z <= DIM; z++)
        {
            mat[x][z] = rotateX(mat[x][z], angle);
        }
}

Point Cylinder::rotateY(Point p)
{
    Point resp;

    if(angY > 2 * PI)
        angY = 0;

    resp.x = cos(angY) * p.x + sin(angY) * p.z;
    resp.y = p.y;
    resp.z = -sin(angY) * p.x + cos(angY) * p.z;

    return resp;
}

Point Cylinder::rotateY(Point p, float angle)
{
    Point resp;

    resp.x = cos(angle) * p.x + sin(angle) * p.z;
    resp.y = p.y;
    resp.z = -sin(angle) * p.x + cos(angle) * p.z;

    return resp;
}

void Cylinder::rotateCylinderY(float angle)
{
    for (int x = 0; x <= DIM; x++)
        for (int z = 0; z <= DIM; z++)
        {
            mat[x][z] = rotateY(mat[x][z], angle);
        }
}

void Cylinder::rotateCylinderY()
{
    angY += getDeltaTime() * 5;
}

Point Cylinder::rotateZ(Point p)
{
    Point resp;
    
    if(angZ > 2 * PI)
        angZ = 0;

    resp.x = cos(angZ) * p.x - sin(angZ) * p.y;
    resp.y = sin(angZ) * p.x + cos(angZ) * p.y;
    resp.z = p.z;

    return resp;
}

Point Cylinder::rotateZ(Point p, float angle)
{
    Point resp;

    resp.x = cos(angle) * p.x - sin(angle) * p.y;
    resp.y = sin(angle) * p.x + cos(angle) * p.y;
    resp.z = p.z;

    return resp;
}

void Cylinder::rotateCylinderZ(float angle)
{
    for (int x = 0; x <= DIM; x++)
        for (int z = 0; z <= DIM; z++)
        {
            mat[x][z] = rotateZ(mat[x][z], angle);
        }
}

void Cylinder::rotateCylinderZ()
{
    angZ += getDeltaTime() * speed;
}

void Cylinder::setSpeed(float speed)
{
    this->speed = speed;
}

float Cylinder::getAngZ()
{
    return angZ;
}

Point Cylinder::translate(Point p)
{
    Point resp;

    resp.x = p.x;
    resp.y = p.y;
    resp.z = p.z - 12;

    return resp;
}

Point Cylinder::translate(Point p, Point offset)
{
    Point resp;

    resp.x = p.x + offset.x;
    resp.y = p.y + offset.y;
    resp.z = p.z + offset.z;

    return resp;
}

void Cylinder::translateCylinder(Point offset)
{
    for (int x = 0; x <= DIM; x++)
        for (int z = 0; z <= DIM; z++)
        {
            mat[x][z] = translate(mat[x][z], offset);
        }
}

// projecao em perspectiva, assumindo camera na origem olhando para z negativo.
Point Cylinder::project(Point p)
{
    float d = distance;
    Point resp;

    resp.x = (p.x * d) / p.z;
    resp.y = (p.y * d) / p.z;
    resp.z = 0;

    return resp;
}

void Cylinder::increaseDistance(float inc)
{
    distance += inc;
}

// aplica sequencia de transformacoes na malha para fazer a animacao e visualizacao.
void Cylinder::transform()
{
    Point p;
    // Processa cada vertice da superficie individualmente.
    for (int x = 0; x <= DIM; x++)
        for (int z = 0; z <= DIM; z++)
        {
            // copia os Points originais
            p = mat[x][z];

            p = rotateZ(p);

            p = rotateY(p);

            // translacao no eixo z
            p = translate(p);

            // projecao em perspectiva
            transf[x][z] = project(p);
        }
}

void Cylinder::project()
{
    Point p;
    // Processa cada vertice da superficie individualmente.
    for (int x = 0; x <= DIM; x++)
        for (int z = 0; z <= DIM; z++)
        {
            // copia os Points originais
            p = mat[x][z];

            p = rotateZ(p);

            p = rotateY(p);

            // translacao no eixo z
            p = translate(p);

            // projecao em perspectiva
            transf[x][z] = project(p);
        }
}

void Cylinder::setAngY(float ang)
{
    angY = ang;
}

float Cylinder::getAngY()
{
    return angY;
}

Point Cylinder::getUpFaceCenter()
{
    Point p;

    float minX, maxX, minY, maxY, minZ, maxZ;

    for(int i = 0; i <= DIM; i++)
    {
        if(i == 0)
        {
            minX = maxX = transf[0][i].x;
            minY = maxY = transf[0][i].y;
            minZ = maxZ = transf[0][i].z;
        }
        else
        {
            if(transf[0][i].x < minX)
                minX = transf[0][i].x;
            if(transf[0][i].x > maxX)
                maxX = transf[0][i].x;
            if(transf[0][i].y < minY)
                minY = transf[0][i].y;
            if(transf[0][i].y > maxY)
                maxY = transf[0][i].y;
            if(transf[0][i].z < minZ)
                minZ = transf[0][i].z;
            if(transf[0][i].z > maxZ)
                maxZ = transf[0][i].z;
        }
    }

    p.x = (minX + maxX) / 2;
    p.y = (minY + maxY) / 2;
    p.z = (minZ + maxZ) / 2;

    return p;
}

Point Cylinder::getDownFaceCenter()
{
    Point p;

    float minX, maxX, minY, maxY, minZ, maxZ;

    for(int i = 0; i <= DIM; i++)
    {
        if(i == 0)
        {
            minX = maxX = transf[DIM][i].x;
            minY = maxY = transf[DIM][i].y;
            minZ = maxZ = transf[DIM][i].z;
        }
        else
        {
            if(transf[DIM][i].x < minX)
                minX = transf[DIM][i].x;
            if(transf[DIM][i].x > maxX)
                maxX = transf[DIM][i].x;
            if(transf[DIM][i].y < minY)
                minY = transf[DIM][i].y;
            if(transf[DIM][i].y > maxY)
                maxY = transf[DIM][i].y;
            if(transf[DIM][i].z < minZ)
                minZ = transf[DIM][i].z;
            if(transf[DIM][i].z > maxZ)
                maxZ = transf[DIM][i].z;
        }
    }

    p.x = (minX + maxX) / 2;
    p.y = (minY + maxY) / 2;
    p.z = (minZ + maxZ) / 2;

    return p;
}

Point Cylinder::getCenter()
{
    return Point(getUpFaceCenter().x + getDownFaceCenter().x / 2, getUpFaceCenter().y + getDownFaceCenter().y / 2, getUpFaceCenter().z + getDownFaceCenter().z / 2);
}

void Cylinder::render()
{
    //transform();

    project();

    CV::color(0, 0, 0);

    for (int x = 0; x <= DIM; x++)
        for (int z = 0; z <= DIM; z++)
        {
            CV::point(transf[x][z].x, transf[x][z].y);
        }

    for (int x = 0; x < DIM; x++)
        for (int z = 0; z < DIM; z++)
        {
            CV::line(transf[x][z].x, transf[x][z].y, transf[x + 1][z].x, transf[x + 1][z].y);
            CV::line(transf[x][z].x, transf[x][z].y, transf[x][z + 1].x, transf[x][z + 1].y);
        }
}