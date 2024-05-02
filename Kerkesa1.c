#include <stdio.h>
#include <string.h>
#define MAX_PERSONA 3

struct person {
    char emri [20];
    char mbiemri [20];
    int mosha;
} person[MAX_PERSONA];

struct student {
    char nrMatrikullimi [20];
};

int personi_vjeter (struct person p[]){
    int i;
    int max = 0;
    for(i=0; i<MAX_PERSONA; i++){
        if(p[i].mosha > max){
            max = p[i].mosha;
        }
    }
    return max;
}

void emriPerpara(struct person p[]){
    int i;
    for(i=0; i<MAX_PERSONA-1; i++){
        if((strcmp(p[i].emri, p[i+1].emri)) == 1){
            printf("\nEmri %s eshte mbrapa emrit %s", p[i].emri, p[i+1].emri);
        }else if((strcmp(p[i].emri, p[i+1].emri)) == 0){
            printf("\nEmrat %s dhe %s jane njesoj",p[i].emri, p[i+1].emri);
        }else if((strcmp(p[i].emri, p[i+1].emri)) == -1){
            printf("\nEmri %s eshte me perpara se emri %s", p[i].emri, p[i+1].emri);
        }
    }
}

void rendit(struct person p[]){
    int i, j;
    for(i=0; i<MAX_PERSONA-1; i++){
        for(j=i+1; j<MAX_PERSONA; j++){
            if((strcmp(p[i].emri, p[j].emri)) == 1){
                struct person temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            else if((strcmp(p[i].emri, p[j].emri)) == 0){
                if((strcmp(p[i].mbiemri, p[j].mbiemri)) == 1){
                    struct person temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
            }
            }
}
    }}


struct person printoDhena(struct person person){
    printf("\nEmri: %s", strlwr(person.emri));
    printf("\nMbiemri: %s", strupr(person.mbiemri));
    //printf("\nEmri.Mbiemri: %s", strcpy(p.emri, p.mbiemri));
    printf("\nMosha: %d", person.mosha);
    return person;
}



int main(){
    int i;
    for(i=0; i<MAX_PERSONA; i++){
        printf("Jep emrin e personit: ");
        scanf("%s", &person[i].emri);
        //printf("Jep emrin e personit: ");
        //gets(person[i].emri);
        printf("Jep mbiemrin e personit: ");
        scanf("%s", &person[i].mbiemri);
        printf("Jep moshen e personit: ");
        scanf("%d", &person[i].mosha);
    }

    printf("\nMosha me e madhe: %d", personi_vjeter(person));
    emriPerpara(person);

    for(i=0; i<MAX_PERSONA; i++){
        printoDhena(person[i]);
        }
// funksioni i shtuar qe kthej numrin e personave me shkronjen e caktuar e dhene nga perdoruesi

           char shkronja;
    printf("\nShkruani shkronjen fillestare te emrit: ");
    scanf(" %c", &shkronja);
    int count_shkronja = 0;
    for (int i = 0; i < MAX_PERSONA; i++) {
        if (person[i].emri[0] == shkronja) {
            count_shkronja++;
        }
    }
    printf("\nNumri i studenteve qe fillon emri me shkronjen %c: %d\n", shkronja, count_shkronja);




return 0;
}
