#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int hasil;

// fungsi faktorial :
int faktorial(int nilai)
{
    hasil = nilai;
    while (nilai > 1)
    {
        hasil = hasil * (nilai - 1);
        nilai = nilai - 1;
    }
    return hasil;
}

int main()
{
    int p, nq, max, x, i, j, n, k, r, s, tr, no;
    int a[100];
    div_t xx;
//2
    for (i = 0; i < 100; i++)
    {
        a[i] = 0;
    }

    
    printf("--------------------------\nPROGRAM GENERATE PERMUTASI\n\n");
    printf("     Oleh Syifa Ayu \n");
    printf("--------------------------\n");

    // input nilai n (jumlah data <maksimal 100>)
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    // input data ke dalam array
    for (i = 1; i <= n; i++)
    {
        printf("Masukkan nilai himpunan a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    // input nilai r
    printf("Nilai r: ");
    scanf("%d", &tr);

    // hitung nilai permutasi
//3    
	p = faktorial(n); 
    nq = faktorial(n - tr);

    if (nq == 0)
        nq = 1;

    max = p / nq;
    printf("Nilai permutasi: %d\nTekan Enter untuk melihat hasil generate permutasi...\n", max);
    getch();

    no = 1; // variabel untuk menampilkan nomor

    // men-generate permutasi dengan algoritma generate next-permutation
    // generate sebanyak nilai permutasi
    for (x = 1; x <= max; x++)
    {
        printf("%3d. ", no);

        for (i = 1; i <= tr; i++)
        {
            printf("%d ", a[i]);
        }
        
        printf("\n");
        no++;
        j = n - 1;

        while (a[j] > a[j + 1])
        {
            j = j - 1; // j adalah subscript terbesar dengan aj < aj+1
        }

        k = n;

        while (a[j] > a[k])
        {
            k = k - 1; // ak adalah integer terkecil dan lebih besar dari aj
        }

        // tukar aj dan ak
//4
        i = a[k];
        a[k] = a[j];
        a[j] = i;
        r = n;
        s = j + 1;
//5
        while (r > s)
        {
            // tukar ar dan as
            i = a[r];
            a[r] = a[s];
            a[s] = i;
            r = r - 1;
            s = s + 1;
        }
    }

    getch();
    return 0;
}

