#include <stdio.h>
#include <math.h>

int get_corners(FILE *in, double *arr_x, double *arr_y, int max_size){
  int cnt = 0;
  while(cnt < max_size && fscanf(in, "%lf %lf", &arr_x[cnt], &arr_y[cnt]) != EOF){
    cnt++;
  }
  return cnt;
}

void output_corners(FILE *out, double *arr_x, double *arr_y, int actual_size){
  for(int idx = 0; idx < actual_size; idx++){
    fprintf(out, "%.3lf %.3lf\n", arr_x[idx], arr_y[idx]);
  }
}

double polygon_area(double *arr_x, double *arr_y, int actual_size){
  double area = 0;
  for(int i = 0; i <= actual_size - 2; i++){
    area += (arr_x[i + 1] + arr_x[i])*(arr_y[i + 1] - arr_y[i]);
  }
  area = 0.5*fabs(area);
  return area;
}

int main(){
  int max_size = 20;
  double arr_x[max_size], arr_y[max_size];
  FILE *in = fopen("data/input.txt", "r");
  FILE *out = fopen("data/output.txt", "w");
  if(in == NULL){
    return 1;
  }

  int actual_size = get_corners(in, arr_x, arr_y, max_size);
  output_corners(out, arr_x, arr_y, actual_size);
  double area = polygon_area(arr_x, arr_y, actual_size);
  printf("The area of polygon is: %.3lf\n", area);

  fclose(in);
  fclose(out);
}
