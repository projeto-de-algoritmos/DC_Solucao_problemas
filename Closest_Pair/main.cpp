#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 10005
#define INF 1e4


double mind = INF;

typedef struct{
    double x, y;
}point;

typedef vector<point> vec;

void dfs(vec p, double x1, double xr){
    if(p.size() == 0){
        return;
    }

    if(p.size() <= 50){
        for (int i = 0; i < p.size(); i++){
            for(int j = i+1; j < p.size(); j++){
                mind = min(mind, sqrt( pow( ( (p[i].x) - (p[j].x) ), 2 ) + pow( ( (p[i].y) - (p[j].y) ), 2 )));
            }
        }
        return;
    }

    vec l, r;

    double x = (x1 + xr)/2;

    for (auto &i: p){
        if(i.x < x){
            l.push_back(i);
        }
        else{
            r.push_back(i);
        }
    }

    dfs(r, x, xr);
    dfs(l, x1, x);

    vec nl, nr;

    for(auto &i:l){
        if(x - i.x < mind){
            nl.push_back(i);
        }
    }

    for(auto &i:r){
        if(i.x - x < mind){
            nr.push_back(i);
        }
    }

    for(auto &i:nl){
        for(auto &j:nr){
            mind = min(mind, sqrt( pow( ( (i.x) - (j.x) ), 2 ) + pow( ( (i.y) - (j.y) ), 2 )));
        }
    }
}

int main(){
    int n;

    while(scanf("%d", &n), n){
        mind = INF;
        vec p;
        
        for(int i = 0; i < n; i++){
            point x;
            scanf("%lf%lf", &(x.x), &(x.y));
            p.push_back(x);
        }

        dfs(p, 0, 40000);

        if(mind + 5e-5 >= INF){
            cout << "INFINITY" << endl;
        }
        else{
            printf("%.4f\n", mind);
        }
    }

}
