#include <stdio.h>
#include <stdlib.h>


typedef struct __polynomial{
    int exp;
    float coef;
    struct __polynomial *next;
} polynomial;

polynomial* newPolynomialNode(int exp, float coef){
    polynomial *tmp = NULL;
    tmp = (polynomial *)malloc(sizeof(polynomial));
    tmp->exp = exp;
    tmp->coef = coef;
    tmp->next = NULL;
    return tmp;
}

void displayPolynomial(polynomial *poly){
    polynomial *current = poly;
    while (current != NULL)
    {
        printf("%fx^%d + ",current->coef,current->exp);
        current = current->next;
    }
    printf("\n");
}

void getInputForPolynomial(polynomial **poly, int deg){
    polynomial *current = NULL;
    float coef;

    for (int i = 0; i <= deg; i++)
    {
        printf("Enter coefficient for exp %d : ",i);
        scanf("%f",&coef);

        if(*poly == NULL){
            *poly = newPolynomialNode(i,coef);
            current = *poly;
        }else{
            current->next = newPolynomialNode(i, coef);
            current = current->next;
        }
    }
}

int isZero(polynomial *poly){
    if(poly == NULL) return 1;
    polynomial *current = poly;
    while (current != NULL)
    {
        if(current->coef != 0) return 0;
        current = current->next;
    }

    return 1;
    
}

float Coef(polynomial *poly){
    return poly->coef;
}

int degree(polynomial *poly){
    polynomial *current = poly;
    int degree;
    while (current != NULL)
    {
        degree = current->exp;
        current = current->next;    
    }

    return degree;
}

int main(){
    int deg1,deg2;
    float coef;
    polynomial *poly1 = NULL;
    polynomial *poly2 = NULL;

    printf("Enter highest power of equation 1 : ");
    scanf("%d",&deg1);
    printf("Enter highest power of equation 2 : ");
    scanf("%d",&deg2);

    printf("%d\n",isZero(poly1));

    getInputForPolynomial(&poly1,deg1);
    getInputForPolynomial(&poly2,deg2);

    displayPolynomial(poly1);
    displayPolynomial(poly2);
    printf("%d\n",isZero(poly1));
    printf("%d\n",isZero(poly2));

    printf("%f\n", Coef(poly1));

    

    return 0;
}