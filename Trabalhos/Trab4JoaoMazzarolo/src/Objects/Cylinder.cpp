#include "Cylinder.h"

Cylinder::Cylinder()
{
    float ang = 0;
    float inc = 2 * PI / DIM;

    for (int i = 0; i <= DIM; i++)
    {
        for (int j = 0; j <= DIM; j++)
        {
            mat[i][j].x = cos(ang);
            mat[i][j].y = sin(ang);
            mat[i][j].z = 2 * j / (float)DIM - 1;
            ang += inc;
        }
    }
}

Point Cylinder::rotateX(Point p)
{
    Point resp;
    ang += 0.00001;

    resp.x = p.x;
    resp.y = cos(ang) * p.y - sin(ang) * p.z;
    resp.z = sin(ang) * p.y + cos(ang) * p.z;

    return resp;
}

Point Cylinder::translate(Point p)
{
    Point resp;

    resp.x = p.x;
    resp.y = p.y - 10;
    resp.z = p.z - 12;

    return resp;
}

// projecao em perspectiva, assumindo camera na origem olhando para z negativo.
Point Cylinder::project(Point p)
{
    float d = -10.0;
    Point resp;

    resp.x = (p.x * d) / p.z;
    resp.y = (p.y * d) / p.z;
    resp.z = 0;

    return resp;
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

            // rotacao no eixo x
            p = rotateX(p);

            // translacao no eixo z
            p = translate(p);

            // projecao em perspectiva
            transf[x][z] = project(p);
        }
}

void Cylinder::render()
{
    // transform();

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