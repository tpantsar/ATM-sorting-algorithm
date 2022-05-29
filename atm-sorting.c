#include <stdio.h>

#define seteli20 20
#define seteli50 50
#define maxNosto 1000

void KysyNostettavaSumma(void); 
void TulostaNostettavaSumma(int rahasumma, int setelit_50, int setelit_20);
int Jaa50EuronSeteleihin(int nostoSumma);
int Jaa20EuronSeteleihin(int setelit_lkm_50, int rahasumma);

int main(void) {

    int setelit_50 = 0, setelit_20 = 0, flag = 0, rahasumma = 0;

    KysyNostettavaSumma();

    while (flag == 0) {
        scanf("%d", &rahasumma);
        if (rahasumma <= maxNosto)
            if (rahasumma >= 0)
                if (rahasumma % 10 == 0)
                    if (rahasumma != 10)
                        if (rahasumma != 30)
                            flag = 1;

        if (flag == 0)
            printf("Yrita uudelleen! > ");
    }
    setelit_50 = Jaa50EuronSeteleihin(rahasumma);
    setelit_20 = Jaa20EuronSeteleihin(setelit_50, rahasumma);
    TulostaNostettavaSumma(rahasumma, setelit_50, setelit_20);

    return(0);
}

// Tulostaa alkuvalikon.
void KysyNostettavaSumma(void) {
    printf("\nOtto-automaatti:\n");
    printf("Valitse nostettava summa (enintaan %d euroa):\n", maxNosto);
    printf("Automaatista saa nostettua vain 20 ja 50 euron seteleita.\n");
    printf("\n< 20 euroa    90 euroa >\n< 40 euroa    140 euroa >\n< 60 euroa    240 euroa >\n< Muu summa\n");
    printf("\nSyota haluamasi summa > ");
}

// Tulostaa nostettavan summan ja setelien lukumäärän.
void TulostaNostettavaSumma(int rahasumma, int setelit_50, int setelit_20) {
    printf("\nNostit automaatista %d euroa.\n", rahasumma);
    printf("Sait %d kpl 50 euron seteleita.\n", setelit_50);
    printf("Sait %d kpl 20 euron seteleita.\n", setelit_20);
}

// Palauttaa nostettavasta summasta 50 euron setelien lukumäärän.
int Jaa50EuronSeteleihin(int nostoSumma) {

    int vahenna_20 = 0, raha = 0, setelit_lkm_50 = 0, jaljella = 0, flag = 0;

    while (flag == 0) {
        raha = (nostoSumma - vahenna_20);
        setelit_lkm_50 = raha / 50;
        jaljella = raha - (setelit_lkm_50 * seteli50);

        if (jaljella % seteli20 == 0)
            flag = 1;
        else
            vahenna_20 += 20;
    }
    return(setelit_lkm_50);
}

// Palauttaa nostettavasta summasta 20 euron setelien lukumäärän.
int Jaa20EuronSeteleihin(int setelit_lkm_50, int rahasumma) {

    int setelit_lkm_20 = 0, jaljella = 0;

    jaljella = rahasumma - (setelit_lkm_50 * seteli50);
    setelit_lkm_20 = jaljella / seteli20;

    return(setelit_lkm_20);
}