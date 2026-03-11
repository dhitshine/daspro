#include <stdio.h>
#include <math.h>

const long double eps = 1e-9;

typedef struct {
  long double x, y;
} Point;

typedef struct {
  Point point;
  long double r, m;
  Point a, v;
} Planet;

typedef struct {
  Point point;
  long double v;
} Kapal;

long double dist(Point p1, Point p2){
  long double dx = p1.x - p2.x;
  long double dy = p1.y - p2.y;
  return sqrt(dx*dx + dy*dy);
}

Point get_dir(Point A, Point B){
  Point dir;
  dir.x = B.x - A.x;
  dir.y = B.y - A.y;
  return dir;
}

long double force(long double G, Planet p1, Planet p2){
  long double jarak = dist(p1.point, p2.point);
  long double gaya = (G * p1.m * p2.m) / (jarak * jarak * jarak);
  return gaya;
}

void update_kapal(Kapal *kapal, Point target, long double time){
  Point dir = get_dir(kapal->point, target);
  long double jarak = dist(kapal->point, target);
  if(jarak > eps){
    long double unit_x = dir.x / jarak;
    long double unit_y = dir.y / jarak;
    kapal->point.x += unit_x * kapal->v * time;
    kapal->point.y += unit_y * kapal->v * time;
  }
}

Point vector_scale(Point a, long double val){
  Point scale;
  scale.x = val*a.x;
  scale.y = val*a.y;
  return scale;
}

int main(){
  Planet pl1, pl2;  // pl1 = fern and pl2 = O
  Kapal kapal;
  long double G, time, max_time;
  scanf("%Lf %Lf %Lf %Lf", &pl1.point.x, &pl1.point.y, &pl1.r, &pl1.m);
  scanf("%Lf %Lf %Lf %Lf", &pl2.point.x, &pl2.point.y, &pl2.r, &pl2.m);
  scanf("%Lf %Lf %Lf", &kapal.point.x, &kapal.point.y, &kapal.v);
  scanf("%Lf %Lf %Lf", &G, &time, &max_time);
  long double curr_time = 0;
  int reachable = 0, collision = 0;
  pl1.v.x = 0, pl2.v.x = 0;
  pl1.v.y = 0, pl2.v.y = 0;
  pl1.a.x = 0, pl2.a.x = 0;
  pl1.a.y = 0, pl2.a.y = 0;
  while(curr_time <= max_time + eps){
    long double dist_fern = dist(kapal.point, pl1.point);
    long double dist_O = dist(kapal.point, pl2.point);
    long double dist_planet = dist(pl1.point, pl2.point);
    if(dist_planet <= pl1.r + pl2.r + eps){
      collision = 1;
      printf("[STATUS] COLLISION=1\n");
      break;
    }
    if(dist_fern <= pl1.r + eps || dist_O <= pl2.r + eps){ 
      reachable = 1;
      if(dist_fern <= pl1.r + eps && dist_O <= pl2.r + eps){    
        printf("[STATUS] TARGET=ANY\n");
      }else if(dist_fern <= pl1.r){
        printf("[STATUS] TARGET=FERN\n");
      }else{
        printf("[STATUS] TARGET=O\n");
      }
      break;
    }
    Point target;
    long double time_fern = dist_fern / kapal.v;
    long double time_o = dist_O / kapal.v;
    if(time_fern <= time_o){  
      target = pl1.point;
    }else{
      target = pl2.point;
    }
    Point F_fern = vector_scale(get_dir(pl1.point, pl2.point), force(G, pl1, pl2));
    Point F_O = vector_scale(get_dir(pl1.point, pl2.point), -force(G, pl1, pl2));
    pl1.a.x = F_fern.x / (pl1.m);
    pl1.a.y = F_fern.y / (pl1.m);
    pl1.v.x += pl1.a.x * time;
    pl1.v.y += pl1.a.y * time;
    pl1.point.x += pl1.v.x * time;
    pl1.point.y += pl1.v.y * time;

    pl2.a.x = F_O.x / (pl2.m);
    pl2.a.y = F_O.y / (pl2.m);
    pl2.v.x += pl2.a.x * time;
    pl2.v.y += pl2.a.y * time;
    pl2.point.x += pl2.v.x * time;
    pl2.point.y += pl2.v.y * time;

    update_kapal(&kapal, target, time);
    curr_time += time;
    if(time < eps){
      break;
    }
  }
  if(!reachable && !collision){
    printf("[STATUS] TARGET=UNREACHABLE\n");
  }
  return 0;
}
