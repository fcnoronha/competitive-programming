// Circle

class Circle {
public:
    Point c;
    double r;

    Circle () {}

    Circle (const Point &c, double r) : c(c), r(r) {}

    /*Interseccao de dois circulos
    OBS: se ha infinitas interseccoes retorna o vetor vazio
    OBS: se existe só um ponto retorna 2 pontos iguais*/
    vector <Point> intersect (Circle b) {
        vector <Point> ret;
        Point c1 = this->c, c2 = b.c;
        double r1 = this->r, r2 = b.r;

        if (c1 == c2) return ret;

        double d = c1.dpp(c2);
        
        if (d > r1 + r2 + EPS) return ret;
        if (d + EPS < abs(r1 - r2)) return ret;

        double a = (r1*r1 - r2*r2 + d*d)/(2.0*d);
        double h = sqrt(max(0.0, r1*r1 - a*a));

        Point pc = c1 + ((c2 - c1)*a)/d;

        /*X EH MENOS E Y EH MAIS*/
        double x = pc.x - ((h*(c2.y - c1.y))/d);
        double y = pc.y + ((h*(c2.x - c1.x))/d);
        ret.pb(Point(x,y));

        x = pc.x + ((h*(c2.y - c1.y))/d);
        y = pc.y - ((h*(c2.x - c1.x))/d);
        ret.pb(Point(x,y));

        return ret;
    }

    // Circumcircle of a triangle, TAKE CARE WITH 3 COLINEAR POINTS
    static Circle circumcircle (const Point &a, const Point &b, const Point &c) {
        Point ab = b - a, bc = c - b;
        Point mab = a + ab * 0.5;
        Point mbc = b + bc * 0.5;

        double a1 = ab.x, b1 = ab.y;
        double c1 = -a1 * mab.x - b1 * mab.y;
        
        double a2 = bc.x, b2 = bc.y;
        double c2 = -a2 * mbc.x - b2 * mbc.y;
        
        double den = a1 * b2 - a2 * b1;

        double x = (-c1 * b2 + b1 * c2)/den;
        double y = (-c2 * a1 + a2 * c1)/den;
        
        Point center(x, y);
        return Circle(center, (a-center).len());
    }

    // Randomize O(p.size())
    // Return circle that covers all point in p with minimum radius
    // Idea: if some point pt is outside of current circle, make new circle with previous points
    // in circle, this circle will have point pt on the border
    // With 3 points on the border its easy to get the circle (Circumcicle)
    static Circle cover (vector <Point> p, vector <Point> border = vector <Point>()) {
        random_shuffle(p.begin(), p.end());

        Circle res;
        if (border.size() == 0) 
            res = Circle(p[0], 0.0);
        else if (border.size() == 1) 
            res = Circle(border[0], 0.0);
        else if (border.size() == 2)
            res = Circle((border[0] + border[1])*0.5, (border[0].dpp(border[1]))/2.0);
        else 
            return circumcircle (border[0], border[1], border[2]);

        vector <Point> p2;
        for (auto pt : p) {
            if (res.c.dpp(pt) > res.r) {
                border.pb(pt);
                res = cover (p2, border);
                border.pop_back();
            }
            p2.pb(pt);
        }

        return res;
    }

    // Retorna os pontos da tangente externa entre os circulo a e b
    // Soh funciona se a e b nao estao contidos inteiramente um no outro
    static vector<Point> outter_tang(Circle a, Circle b) {
        vector<Point> ret;
        // a eh o circulo de maior area
        if(a.r < b.r) 
            swap(a, b);
        // raio iguais n tem ponto de interseccao das duas tangentes
        // os vetor do raio ao ponto da tangente eh perpenditular ao vetor que liga os centros
        if(abs(a.r-b.r) < EPS) {
            double dist = a.c.dpp(b.c);
            Point vv = a.c-b.c;
            vv = Point(vv.y, -vv.x);

            double len_ratio = a.r / dist;
            ret.pb(a.c + vv*len_ratio);
            ret.pb(a.c - vv*len_ratio);

            len_ratio = b.r / dist;
            ret.pb(b.c + vv*len_ratio);
            ret.pb(b.c - vv*len_ratio);

            return ret;
        }
        return ret;

        double dist = a.c.dpp(b.c);
        // distancia entre a.c e o ponto de interseccao das tangentes
        double h = (dist * a.r) / (a.r - b.r);

        // ponto de interseccao das tangentes
        Point p = a.c + ((b.c - a.c) * (h / dist));

        double len_ratio = sqrt(h*h - a.r*a.r) / h;
        ret.pb( p + (a.c-p).rotaciona(asin(a.r/h))*len_ratio);
        ret.pb( p + (a.c-p).rotaciona(-asin(a.r/h))*len_ratio );

        len_ratio = sqrt((h-dist)*(h-dist) - b.r*b.r) / (h-dist);
        ret.pb( p + (b.c-p).rotaciona(asin(b.r/(h-dist)))*len_ratio );
        ret.pb( p + (b.c-p).rotaciona(-asin(b.r/(h-dist)))*len_ratio );

        return ret;
    }
};