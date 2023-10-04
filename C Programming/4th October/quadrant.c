#include <stdio.h>

int main(){

    int x, y;
    
    printf("Enter Coordinates of x,y (separated by space): ");
    scanf("%d %d", &x, &y);

    if ((x>0) && (y>0)){

        printf("(%d, %d) lies in 1st Quadrant.", x, y);
    }

    else if ((x<0) && (y>0)){
        
        printf("(%d, %d) lies in 2nd Quadrant.", x, y);
    }

    else if ((x<0) && (y<0)){

        printf("(%d, %d) lies in 3rd Quadrant.", x, y);
    }

    else if ((x==0) && (y==0)){

        printf("(%d, %d) is Origin.", x, y);
    }

    else if ((x==0)){

        printf("(%d, %d) lies on Y axis.", x, y);
    }

    else if ((y==0)){

        printf("(%d, %d) lies on X axis.", x, y);
    }

    else{

        printf("(%d, %d) lies in 4th Quadrant.", x, y);
    }

    return 0;
}