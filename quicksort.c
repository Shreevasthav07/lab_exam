#include<stdio.h>

typedef struct {
    char name[50];
    int marks;
}Student;

void swap(Student *a, Student *b){
    Student t = *a;
    *a = *b;
    *b = t;
}

int partition(Student a[], int low, int high){
    int pivot = a[high].marks;
    int i = low-1;
    for(int j = low;j<high;j++){
        if(a[j].marks>= pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

void quicksort(Student a[], int low, int high){
    if(low<high){
        int p = partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    } 
    
}
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student s[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);

        printf("Enter marks of %s: ", s[i].name);
        scanf("%d", &s[i].marks);
    }

    quicksort(s, 0, n - 1);

    printf("\nStudents sorted by marks (Descending):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", s[i].name, s[i].marks);
    }

    return 0;
}
