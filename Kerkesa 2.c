#include <stdio.h>
#include <string.h>

#define MAX_PERSONA 3
#define MAX_NAME_LENGTH 20

struct person {
    char emri[MAX_NAME_LENGTH];
    char mbiemri[MAX_NAME_LENGTH];
    int mosha;
} person[MAX_PERSONA];

int personi_vjeter(struct person p[]) {
    int i;
    int max = 0;
    for (i = 0; i < MAX_PERSONA; i++) {
        if (p[i].mosha > max) {
            max = p[i].mosha;
        }
    }
    return max;
}

void emriPerpara(struct person p[]) {
    int i;
    for (i = 0; i < MAX_PERSONA - 1; i++) {
        if ((strcmp(p[i].emri, p[i + 1].emri)) == 1) {
            printf("\nEmri %s eshte mbrapa emrit %s", p[i].emri, p[i + 1].emri);
        } else if ((strcmp(p[i].emri, p[i + 1].emri)) == 0) {
            printf("\nEmrat %s dhe %s jane njesoj", p[i].emri, p[i + 1].emri);
        } else if ((strcmp(p[i].emri, p[i + 1].emri)) == -1) {
            printf("\nEmri %s eshte me perpara se emri %s", p[i].emri, p[i + 1].emri);
        }
    }
}

void rendit(struct person p[]) {
    int i, j;
    for (i = 0; i < MAX_PERSONA - 1; i++) {
        for (j = i + 1; j < MAX_PERSONA; j++) {
            if ((strcmp(p[i].emri, p[j].emri)) == 1) {
                struct person temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            } else if ((strcmp(p[i].emri, p[j].emri)) == 0) {
                if ((strcmp(p[i].mbiemri, p[j].mbiemri)) == 1) {
                    struct person temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
    }
}

struct person printoDhena(struct person person) {
    printf("\nEmri: %s", strlwr(person.emri));
    printf("\nMbiemri: %s", strupr(person.mbiemri));
    printf("\nMosha: %d", person.mosha);
    return person;
}

struct person personiMbiemriMeGjate(struct person p[]) {
    struct person longestLastNamePerson = p[0];

    for (int i = 1; i < MAX_PERSONA; i++) {
        if (strlen(p[i].mbiemri) > strlen(longestLastNamePerson.mbiemri)) {
            longestLastNamePerson = p[i];
        }
    }

    return longestLastNamePerson;
}

int main() {
    int i;
    for (i = 0; i < MAX_PERSONA; i++) {
        printf("Jep emrin e personit: ");
        scanf("%s", person[i].emri);
        printf("Jep mbiemrin e personit: ");
        scanf("%s", person[i].mbiemri);
        printf("Jep moshen e personit: ");
        scanf("%d", &person[i].mosha);
    }

    printf("\nMosha me e madhe: %d", personi_vjeter(person));
    emriPerpara(person);

    struct person longestLastNamePerson = personiMbiemriMeGjate(person);
    printf("\nPersoni me mbiemrin me te gjate eshte:\n");
    printf("Emri: %s\n", longestLastNamePerson.emri);
    printf("Mbiemri: %s\n", longestLastNamePerson.mbiemri);
    printf("Mosha: %d\n", longestLastNamePerson.mosha);

    for (i = 0; i < MAX_PERSONA; i++) {
        printoDhena(person[i]);
    }

    return 0;
}
