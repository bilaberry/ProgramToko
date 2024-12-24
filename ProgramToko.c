#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>


#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int price;
    int quantity;
} Item;

typedef struct {
    char name[50];
    int price;
    int quantity;
} Topping;

Item menu[] = {
    {"Seblak", 10000, 0},
    {"Baso Aci", 8000, 0},
    {"Cireng", 12000, 0},
    {"Cimol", 8000, 0},
    {"Mandi", 5000, 0},
    {"Pop Ice", 5000, 0}
};

Topping toppings[] = {
    {"Telur", 2500, 0},
    {"Mie", 2000, 0},
    {"Dumpling", 1500, 0},
    {"Pangsit", 3000, 0},
    {"Sayur", 1000, 0},
    {"Jamur Enokki", 2000, 0},
    {"Cuanki", 3000, 0},
    {"Ceker", 2000, 0},
    {"Pilus", 1000, 0}
};

int pilihan, angka, diskon, harga, total=0, uang;
int dapat_diskon = 0;

int employee();
void selamatDatang();
void welkam();
void daftarBarang();
void daftarTopping();
void menuBayar();
void keluar();
void pilihbarang();
void pilihTopping();
int games();
int bayar();
int beliwak();
int welkamawal();
int hitung_diskon();
void bill();

void selamatDatang()
{
    printf("==========================================\n");
    printf("|\tSelamat Datang di Toko Copi\t |\n");
    printf("==========================================\n");
}
void welkam()
{
    
    printf("Ada yang bisa kami bantu?\n");
    printf("==========================================\n");
    printf("| 1. Beli Makanan\t\t\t |\n");
    printf("| 2. Bayar\t\t\t\t |\n");
    printf("| 3. Game\t\t\t\t |\n");
    printf("| 4. Cetak Struk \t\t\t |\n");
    printf("| 5. Topping of the month\t\t |\n");
    printf("| 6. Exit\t\t\t\t |\n");
    printf("==========================================\n");
}
void daftarBarang()
{
    printf("Daftar Barang\n");
    printf("==========================================\n");
    printf("| 1. Seblak\t\t\tRp.10000 |\n");
    printf("| 2. Baso Aci\t\t\tRp.8000  |\n");
    printf("| 3. Cireng\t\t\tRp.12000 |\n");
    printf("| 4. Cimol \t\t\tRp.8000  |\n");
    printf("| 5. Mandi\t\t\tRp.5000  |\n");
    printf("| 6. Pop Ice\t\t\tRp.5000  |\n");
    printf("| 7. Exit\t\t\t\t |\n");
    printf("==========================================\n");
}

void daftarTopping()
{
    printf("Daftar Topping\n");
    printf("==========================================\n");
    printf("| 1. Telur\t\t\tRp.2500  |\n");
    printf("| 2. Mie\t\t\tRp.2000  |\n");
    printf("| 3. Dumpling\t\t\tRp.1500  |\n");
    printf("| 4. Pangsit\t\t\tRp.3000  |\n");
    printf("| 5. Sayur\t\t\tRp.1000  |\n");
    printf("| 6. Jamur Enokki\t\tRp.2000  |\n");
    printf("| 7. Cuanki\t\t\tRp.3000  |\n");
    printf("| 8. Ceker\t\t\tRp.2000  |\n");
    printf("| 9. Pilus\t\t\tRp. 1000 |\n");
    printf("| 10. Exit\t\t\t\t |\n");
    printf("==========================================\n");
}
void menuBayar()
{
    printf("==========================================\n");
    printf("| 1. Bayar sekarang\t\t\t |\n");
    printf("| 2. Belanja lagi\t\t\t |\n");
    printf("==========================================\n");
}

void keluar()
{
    printf("==========================================================\n");
     char* pesan[] = {
        "T", "e", "r", "i", "m", "a", " ", "K", "a", "s", "i", "h", " ",
        "t", "e", "l", "a", "h", " ", "b", "e", "r", "b", "e", "l", "a", "n", "j", "a", " ", 
        "d", "i", " ", "T", "o", "k", "o", " ", "C", "o", "p", "i", "!" };
    
    for (int i = 0; i < sizeof(pesan) / sizeof(pesan[0]); i++)
    {
        printf("\033[1;32m%s", pesan[i]);
        Sleep(100); 
        printf("\033[0m");
    }
    printf("\n");
    printf("==========================================================\n");
    exit(0);
}

void beriRating()
{
    int rating;
    printf("\nSilakan beri rating untuk layanan kami (1-5 bintang): ");
    scanf("%d", &rating);
    if (rating >= 1 && rating <= 5)
    {
        printf("Terima kasih atas rating %d bintangnya!\n", rating);
    }
    else
    {
        printf("Rating yang Anda masukkan tidak valid.\n");
    }
}

void pilihTopping()
{
    printf("\nDaftar Topping:\n");
    printf("==========================================\n");
    for (int i = 0; i < sizeof(toppings) / sizeof(toppings[0]); i++) {
        printf("%d. %s - Rp.%d\n", i + 1, toppings[i].name, toppings[i].price);
    }
    printf("%d. Kembali\n", sizeof(toppings) / sizeof(toppings[0]) + 1);
    printf("==========================================\n");
}

void pilihbarang()
{
   printf("\nDaftar Makanan:\n");
    printf("==========================================\n");
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        printf("%d. %s - Rp.%d\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("%d. Kembali\n", sizeof(menu) / sizeof(menu[0]) + 1);
    printf("==========================================\n");
}

int games()
{
    srand(time(0));
    angka = rand() % 100 + 1; 
    printf("======================================================\n");
    printf("| \tSelamat datang di permainan tebak Topping!    |\n");
    printf("======================================================\n");
    char *topping[] = {
        "Telur", "Mie", "Dumpling", "Pangsit", "Sayur",
        "Jamur enoki", "Cuanki", "Ceker", "Pilus"
    };
    int jumlahtopping = sizeof(topping) / sizeof(topping[0]);
    srand(time(0));
    int toppinghariiniindex = rand() % jumlahtopping;

    printf("Daftar topping yang tersedia:\n");
    for (int i = 0; i < jumlahtopping; i++)
    {
        printf("%d. %s\n", i + 1, topping[i]);
    }

    int tebakanpengguna = 0; 
    int harga;
    int kesempatan = 2;
    int benar = 0;

    do
    {
        printf("\nTebak topping of the day (masukkan nomor topping): ");
        if (scanf("%d", &tebakanpengguna) != 1){
            printf("Inputan harus berupa angka\n");
            while (getchar() != '\n');
        } else if (tebakanpengguna <= 0 || tebakanpengguna > 9){
            printf("Angka harus dimulai dari 0 - 9\n");
        } else if (tebakanpengguna >= 1 && tebakanpengguna <= jumlahtopping && tebakanpengguna - 1 == toppinghariiniindex){
            printf("Selamat, anda benar! %s adalah topping of the day. Anda mendapatkan diskon 10%%.\n", topping[toppinghariiniindex]);
            dapat_diskon = 1;
            benar = 1;
            break;
        } else{
            kesempatan--;
            if (kesempatan > 0){
                printf("Maaf, tebakan anda salah. Anda masih memiliki %d kesempatan.\n", kesempatan);
            } else{
                printf("Maaf, tebakan anda salah. Anda tidak memiliki kesempatan lagi.\n");
                printf("Topping of the day adalah %s.\n", topping[toppinghariiniindex]);
            }
        }
    } while (kesempatan > 0);
    return benar;
}
int welkamawal(void welkam(), int pilihan, int games(), void keluar(), int employee()) {
    welkam();
    do {
        printf("Pilih menu yang ingin anda lakukan: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("Inputan harus berupa angka\n");
            while (getchar() != '\n');
        } else if (pilihan <= 0 || pilihan > 6) {
            printf("Angka harus dimulai dari 1-6\n");
        } else if (pilihan == 1) {
            system("Cls");
            beliwak();
        } else if (pilihan == 2) {
            bayar();
        } else if (pilihan == 3) {
            system("cls");
            games();
            while (getchar() != '\n');
            printf("Tekan tombol apapun untuk kembali");
            getchar();
            system("Cls");
            welkamawal(welkam, pilihan, games, keluar, employee);
        } else if (pilihan == 4) {
            bill();
            while (getchar() != '\n');
            printf("Tekan tombol apapun untuk kembali");
            getchar();
            system("Cls");
            welkamawal(welkam, pilihan, games, keluar, employee);
        } else if (pilihan == 5) {
            system("cls");
            employee();
            while (getchar() != '\n');
            printf("Tekan tombol apapun untuk kembali");
            getchar();
            system("Cls");
            welkamawal(welkam, pilihan, games, keluar, employee);
        } else if (pilihan == 6) {
            system("Cls");
            printf("\nProses pembayaran selesai.\n");
            beriRating();
            printf("\n");
            keluar();
            // total = 0; // Reset total setelah keluar
            return 0;
        } else {
            printf("Pilihan tidak valid\n");
            getch();
        }
    } while (1);
}

int beliwak(){
    int barang, jumlah, topping, jumlahtopping;
    int totaltopping = 0;
    while (1)
    {
        daftarBarang();
        do
        {
        printf("Pilih barang yang ingin dibeli: ");
        if (scanf("%d", &barang) != 1){
            printf("Inputan harus berupa angka\n");
            while (getchar() != '\n');
        } else if (barang  <=0 ||  barang > 7){
            printf("Angka harus dimulai dari 1-7\n");
        } else  {
            break;
        }
        } while (1);
        
        
        totaltopping = 0;
        if (barang == 1 || barang == 2)
        {
            do
            {
                system("Cls");
                daftarTopping();
                do
                {   
                    printf("Pilih topping yang ingin dibeli: ");
                    if (scanf("%d", &topping) != 1)
                    {
                        printf("Inputan harus berupa angka\n");
                        while (getchar() != '\n');
                    } else if (topping  <=0 ||  topping > 10){
                        printf("Angka harus dimulai dari 1-10\n");
                    } else if (topping == 10)
                    {
                        break;
                    }
                    else if (topping >= 1 && topping <= 9)
                    {
                        do
                        {
                            printf("Masukkan jumlah topping yang ingin dibeli: ");
                            if (scanf("%d", &jumlahtopping) != 1)
                            {
                                printf("Inputan harus berupa angka\n");
                                while (getchar() != '\n');
                            } else if (jumlahtopping <= 0)
                            {
                                printf("Jumlah topping harus lebih besar dari 0\n");
                            } else
                            {
                                break;
                            }
                        } while (1);
                        toppings[topping - 1].quantity += jumlahtopping;
                        totaltopping += toppings[topping - 1].price * jumlahtopping;
                        printf("Topping berhasil ditambahkan.\n");
                        system("Cls");
                        daftarTopping();
                    }
                    else
                    {
                        printf("Pilihan topping tidak valid\n");
                    }
                } while (1);
                
                
            } while (topping >= 1 && topping <= 9);
            total += totaltopping + menu[barang - 1].price ;
            menu[barang - 1].quantity += 1;
            system("Cls");
            continue;
        }
        if (barang >= 1 && barang <= 6) { 
            printf("Masukkan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah);
            menu[barang - 1].quantity += jumlah;
            system("Cls");
            total += menu[barang - 1].price * jumlah + totaltopping; 
        } else if (barang == 7) {
            system("Cls");
            welkamawal(welkam, pilihan, games, keluar, employee);
            break;
        }
    }

    return total;

}

int bayar(){
int menubayar;
int kembalian = uang - total;
int diskon = 0;
int harga_diskon = total ;
    system("cls");

    if (total == 0) {
        printf("Anda belum belanja apapun. Silahkan belanja dulu \n");
        while (getchar() != '\n');
        printf("Tekan tombol apapun untuk kembali");
        getchar();
        system("cls");
        welkamawal(welkam, pilihan, games, keluar, employee);
    } else 

    printf("Total belanjaan Anda: Rp.%d\n", total);
    if (dapat_diskon == 1)
    {
        printf("Anda mendapatkan diskon 10%%\n");
        diskon = total * 0.1; 
        harga_diskon = total - diskon;
        printf("Harga belanja anda setelah di diskon adalah: Rp.%d\n", harga_diskon);

    }
    menuBayar();
    while (1)
    {
        printf("Masukkan pilihan menu: ");
        scanf("%d", &menubayar);
        if (menubayar != 1 && menubayar != 2)
        {
            printf("Pilihan tidak valid\n");
        }
        else
        {
            break;
        }
    }

    if (menubayar == 1)
    {
        printf("Masukkan jumlah uang yang ingin Anda bayar: Rp.");
        scanf("%d", &uang);
        if (uang >= harga_diskon)
        {
            hitung_diskon();
            total = 0;
        }
        else
        {
            printf("Uang anda tidak mencukupi\n");
            printf("Uang anda kurang Rp.%d\n", total - uang);
            printf("Silahkan cari uang\n");
        }
    }
    else if (menubayar == 2)
    {
        while (getchar() != '\n');
        printf("Tekan tombol apapun untuk kembali");
        getchar();
        system("Cls");
        welkamawal(welkam, pilihan, games, keluar, employee);
    }
    else
    {
        printf("Pilihan tidak valid\n");
    }
        bill();
        while (getchar() != '\n');
        printf("Tekan tombol apapun untuk kembali");
        getchar();
        system("Cls");
        welkamawal(welkam, pilihan, games, keluar, employee);
        
}

// }
int employee()
{
    char *employees[] = {"Telur", "Mie", "Dumpling", "Pangsit", "Sayur",
        "Jamur enoki", "Cuanki", "Ceker", "Pilus"};
    int karyawan = sizeof(employees) / sizeof(employees[0]);

    srand(time(NULL));

    int pilihan;
    do
    {
    printf("Klik 1 untuk melihat employees of the month: ");
    if (scanf("%d", &pilihan) != 1)
    {
        printf("Inputan harus berupa angka\n");
        while (getchar() != '\n');
    } else  if (pilihan == 1)
    {
        break;
    }
    else
    {
        printf("Silakan ketik 1.\n");
    }
    } while (1);
    int indeks_acak = rand() % karyawan;
    printf("Toppings of the month adalah %s\n", employees[indeks_acak]);
    

    return 0;
}

int hitung_diskon()
{

    int kembalian = uang - total;
    int diskon = 0;
    int harga_diskon = total ;

    printf("Uang yang dibayar: Rp.%d\n", uang);

    if (dapat_diskon == 1)
    {
        diskon = total * 0.1; 
        harga_diskon = total - diskon;
        printf("Harga belanja anda setelah di diskon adalah: Rp.%d\n", harga_diskon);
        printf("Kembalian Anda: Rp.%d\n", uang-harga_diskon);
    }
    else
    {
        printf("Kembalian Anda: Rp.%d\n", kembalian);
    }
    // total = 0;
    dapat_diskon = 0;
    while (getchar() != '\n');
    printf("Tekan tombol apapun untuk kembali");
    getchar();
    system("Cls");
    welkamawal(welkam, pilihan, games, keluar, employee);
    
}

void bill() 
{
    
    FILE *file = fopen("ror.txt", "w"); 

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    } else {
        printf("File opened successfully.\n");
    }

    fprintf(file, "==========================================\n");
    fprintf(file, "                 Toko Copi                \n");
    fprintf(file, "               Bill Receipt               \n");
    fprintf(file, "==========================================\n");
    fprintf(file, "Menu yang dibeli:\n");

    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        if (menu[i].quantity > 0) {
            fprintf(file, "%s x%d - Rp.%d\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }

    fprintf(file, "\nToppings Purchased:\n");
    for (int i = 0; i < sizeof(toppings) / sizeof(toppings[0]); i++) {
        if (toppings[i].quantity > 0) {
            fprintf(file, "%s x%d - Rp.%d\n", toppings[i].name, toppings[i].quantity, toppings[i].price * toppings[i].quantity);
        }
    }

    fprintf(file, "------------------------------------------\n");
    fprintf(file, "Total Amount: Rp.%d\n", total);
    
    int diskon = 0;
    diskon = total * 0.1; 
    if (dapat_diskon = 1) {
        fprintf(file, "Discount: Rp.%d\n", diskon);
    }
    fprintf(file, "Tunai: Rp.%d\n", uang);  
    fprintf(file, "Kembalian: Rp.%d\n", uang - total);
    total = 0;

    fprintf(file, "==========================================\n");
    fclose(file); 

    printf("Bill disimpan di 'ror.txt'.\n");
}

int main()
{
    system("Cls");
    selamatDatang();
    welkamawal(welkam, pilihan, games, keluar, employee);
    beriRating();
}

