#include <stdio.h>
#include <stdlib.h>

typedef struct point //defining a point with x and y co-ordinates
{
    float x;
    float y;
} Point;

typedef struct line // a line with two point structures
{
    Point p1;
    Point p2;
} Line;

typedef struct polygon // a polygon with n(>2) number of lines which come from n points
{
    int n_of_points;
    Line *lines;
} Polygon;

Line create_line(Point p1, Point p2) // create a line with two points
{
    Line l;
    l.p1 = p1;
    l.p2 = p2;
    return l;
}

Point create_point(float x, float y) // create a point with x and y values
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

Polygon create_polygon(int n, Point *ps) // creates polygon of n sides taking n points as input
{
    Polygon poly;
    poly.n_of_points = n;

    poly.lines = (Line *)malloc(n * sizeof(Line));

    int i;
    for (i = 0; i < n; i++)
    {
        poly.lines[i] = create_line(ps[i], ps[(i + 1) % n]);
    }

    free(ps);

    return poly;
}

void take_points(Point *ps, int n) // taking the user-input of points
{
    int i;
    printf("\n--points in clockwise---");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter %d point(x,y): ", i + 1);
        scanf("%f %f", &ps[i].x, &ps[i].y);
    }
}

void print_points(Point *ps, int n) // just to print the points of a points array
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n%0.2f %0.2f", ps[i].x, ps[i].y);
    }
}

int infinite_slope(Line l) // to check whether a line has infinte slope or not
{
    return (l.p2.x - l.p1.x) == 0;
}

int equal_slope(Line l1, Line l2) // check if two lines are equally sloped
{
    if (infinite_slope(l1) && infinite_slope(l2))
    {
        return 1;
    }
    else if (infinite_slope(l1) || infinite_slope(l2))
    {
        return 0;
    }
    return (((l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x)) == ((l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x)));
}

int line_intersect(Line l1, Line l2) // check if two lines intersect
{
    if (equal_slope(l1, l2))
    {
        return 0;
    }
    float b1 = l1.p2.x - l1.p1.x;
    float a1 = l1.p1.y - l1.p2.y;
    float c1 = (l1.p1.x) * (l1.p2.y) - (l1.p2.x) * (l1.p1.y);

    float b2 = l2.p2.x - l2.p1.x;
    float a2 = l2.p1.y - l2.p2.y;
    float c2 = (l2.p1.x) * (l2.p2.y) - (l2.p2.x) * (l2.p1.y);

    float final_x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);

    int res = (final_x < l1.p2.x) ^ (final_x < l1.p1.x) && (final_x < l2.p2.x) ^ (final_x < l2.p1.x);

    return res;
}

int polygon_intersect(Polygon pol1, Polygon pol2) //CHECK IF POLYGONS INTERSECT
{
    int i, j;

    for (i = 0; i < pol1.n_of_points; i++)
    {
        for (j = 0; j < pol2.n_of_points; j++)
        {
            if (line_intersect(pol1.lines[i], pol2.lines[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{

    int m, n, i;
    float x, y;
    Point p;
    Point *ps1, *ps2;

    while (1)
    {
        printf("\nEnter the number of points in the two polygons: ");
        scanf("%d %d", &m, &n);

        if (m <= 2 || n <= 2) // NUMBER OF POINTS IN A POLYGON MUST BE >2
        {
            printf("\nNumber of points of a polygon must be more than 2...");
        }
        else
        {
            break;
        }
    }

    ps1 = (Point *)malloc(m * sizeof(Point));
    ps2 = (Point *)malloc(n * sizeof(Point));
    printf("\n-----ENTER FIRST POLYGON POINTS---------");
    take_points(ps1, m);

    printf("\n-----ENTER SECOND POLYGON POINTS---------");
    take_points(ps2, n);

    Polygon pol1 = create_polygon(m, ps1);
    Polygon pol2 = create_polygon(n, ps2);

    // print_points(ps1, m);
    // print_points(ps2, n);

    if (polygon_intersect(pol1, pol2))
    {
        printf("\nTwo polygons intersects");
    }
    else
    {
        printf("\nTwo Polygons Don't intersect...");
    }

    free(pol1.lines);
    free(pol2.lines);
}
