#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

const int max_array = 4; // max array pada menu2
// Deklarasi Struct Galaksi

struct Stack // Struct Pertama
{
    int top;
    string data[max_array];
};

struct Galaksi // Struct Kedua
{
    string nama;
    string jarak;
    string jPlanet;
    Galaksi *next;
};

Galaksi *head; // Node Awal
Galaksi *tail; // Node Akhir

void initStack(Stack &stack)
{
    stack.top = -1;
}

bool isFull(const Stack &stack)
{
    return stack.top == max_array - 1;
}

bool isEmpty(const Stack &stack)
{
    return stack.top == -1;
}

void push(Stack &stack, const string &value)
{
    if (isFull(stack))
    {
        cout << "Stack penuh. Data tidak dapat ditambahkan." << endl;
    }
    else
    {
        stack.top++;
        stack.data[stack.top] = value;

        // Mendapatkan nama zodiak yang baru ditambahkan
        string zodiacName = value.substr(value.find_last_of(' ') + 1);
        cout << "Data \"" << zodiacName << "\" berhasil ditambahkan." << endl;
    }
}

void pop(Stack &stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack kosong. Tidak ada data yang dapat dihapus." << endl;
    }
    else
    {
        string removedValue = stack.data[stack.top];
        stack.top--;
        cout << "Data \"" << removedValue << "\" berhasil dihapus." << endl;
    }
}

void display(const Stack &stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack kosong." << endl;
    }
    else
    {
        cout << "Isi Bintang: " << endl;
        for (int i = stack.top; i >= 0; i--)
        {
            cout << "\"" << stack.data[i] << "\" " << endl;
        }
        cout << endl;
    }
}

// Inisialisasi Galaksi
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Belakang
void tambahBelakang(string jPlanet, string jarak, string nama)
{
    // Buat Galaksi baru
    Galaksi *baru = new Galaksi;
    baru->jarak = jarak;
    baru->nama = nama;
    baru->jPlanet = jPlanet;
    baru->next = NULL;

    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah List
int hitungList()
{
    Galaksi *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    Galaksi *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        string dataLama = hapus->jarak;
        sebelum->next = bantu;
        delete hapus;
        cout << "Data " << dataLama << " berhasil dihapus" << endl;
    }
}

// Ubah Tengah
void ubahTengah(string jPlanet, string jarak, string nama, int posisi)
{
    Galaksi *bantu;
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            string dataLamaNama = bantu->nama;
            string dataLamaJarak = bantu->jarak;
            bantu->jarak = jarak;
            bantu->nama = nama;
            bantu->jPlanet = jPlanet;
            cout << "Data " << dataLamaNama << " dengan jarak " << dataLamaJarak << " telah diganti dengan data " << nama << " dengan jarak " << jarak << "!" << endl;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Tampilkan List
void tampil()
{
    Galaksi *bantu = head;

    cout << "+----------------------------------------------------------------+" << endl;
    cout << "|                         DAFTAR GALAKSI                         |" << endl;
    cout << "+----------------------------------------------------------------+" << endl;
    cout << "|  NAMA GALAKSI    |    JARAK DENGAN BUMI    |   JUMLAH PLANET   |" << endl;
    cout << "+----------------------------------------------------------------+" << endl;
    while (bantu != NULL)
    {
        cout << "|" << setiosflags(ios::left) << setw(17) << bantu->nama << " | ";
        cout << setiosflags(ios::left) << setw(8) << bantu->jarak << " tahun cahaya";
        cout << setiosflags(ios::left) << setw(12) << " | ";
        cout << setiosflags(ios::left) << setw(8) << bantu->jPlanet << " | " << endl;
        cout << "+----------------------------------------------------------------+" << endl;

        bantu = bantu->next;
    }
}

struct Queue
{
    Galaksi *front;
    Galaksi *rear;
};
void initQueue(Queue &queue)
{
    queue.front = nullptr;
    queue.rear = nullptr;
}

bool isQueueEmpty(const Queue &queue)
{
    return queue.front == nullptr;
}

void enqueue(Queue &queue, const string &nama, const string &jarak)
{
    Galaksi *newGalaksi = new Galaksi;
    newGalaksi->nama = nama;
    newGalaksi->jarak = jarak;
    newGalaksi->next = nullptr;

    if (isQueueEmpty(queue))
    {
        queue.front = newGalaksi;
        queue.rear = newGalaksi;
    }
    else
    {
        queue.rear->next = newGalaksi;
        queue.rear = newGalaksi;
    }
}

void dequeue(Queue &queue)
{
    if (isQueueEmpty(queue))
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Galaksi *temp = queue.front;
    queue.front = queue.front->next;
    delete temp;

    if (queue.front == nullptr)
    {
        queue.rear = nullptr;
    }
}

void displayQueue(const Queue &queue)
{
    if (isQueueEmpty(queue))
    {
        cout << "Kosong" << endl;
        return;
    }
    int a = 1;

    Galaksi *current = queue.front;

    while (current != nullptr)
    {
        cout << "Bulan Dengan Suhu Terendah Ke-" << a << endl;
        cout << "Nama Bulan: " << current->nama << endl;
        cout << "Suhu Bulan: " << current->jarak << " Derajat Celcius" << endl;
        current = current->next;
        cout << endl;
        a++;
    }
}

const int maxSimpul = 10;
string simpul[maxSimpul];
int busur[maxSimpul][maxSimpul];
int imelda_2211102001;
void tampilGraph()
{
    cout << setw(10) << " ";
    for (int kolom = 0; kolom < imelda_2211102001;
         kolom++)
    {
        cout << setw(10) << simpul[kolom];
    }
    cout << endl;
    for (int baris = 0; baris < imelda_2211102001;
         baris++)
    {
        cout << setw(10) << simpul[baris];
        for (int kolom = 0; kolom < imelda_2211102001;
             kolom++)
        {
            cout << setw(10) << busur[baris][kolom];
        }
        cout << endl;
    }
}

int main()
{

    int pilihan, posisi;
    string jPlanet, jarak, nama, nim, dataLama;
menu:
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                                                             |" << endl;
    cout << "|                      S I G A L A K S                        |" << endl;
    cout << "|              S I S T E M  I N F O R M A S I                 |" << endl;
    cout << "|                      G A L A K S I                          |" << endl;
    cout << "|                                                             |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|1. FAKTA UNIK GALAKSI" << endl;
    cout << "|2. BINTANG" << endl;
    cout << "|3. BULAN" << endl;
    cout << "|4. JENIS GALAKSI" << endl;
    cout << "|5. GRAPH" << endl;
    cout << "|0. KELUAR" << endl;
    cout << "Masukan Pilihan Anda: ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        system("CLS");
        int exit;
        {
            // Implementasi menu "Apa Itu Galaksi"
            cout << "+-------------------+" << endl;
            cout << "| PENGERTIAN        |" << endl;
            cout << "+-------------------+" << endl;
            cout << "Galaksi adalah kumpulan bintang, sistem bintang, debu, gas antar bintang\ndan materi gelap yang terikat oleh gravitasi. Galaksi memiliki berbagai\nbentuk dan ukuran, dan terdiri dari miliaran bintang serta berbagai jenis\nsistem bintang seperti planet, asteroid, dan komet. Galaksi juga memiliki\nberagam jenis dan klasifikasi berdasarkan karakteristiknya." << endl;
            cout << endl;
            cout << "+----------------------+" << endl;
            cout << "| BENTUK GALAKSI       |" << endl;
            cout << "+----------------------+" << endl;
            cout << "1. Galaksi Elips\nUmumnya tidak memiliki cakram datar atau lengan spiral seperti galaksi\nspiral. Galaksi eliptikal biasanya terdiri dari bintang-bintang yang lebih\ntua dan memiliki populasi bintang yang lebih tua secara keseluruhan.\n " << endl;
            cout << "2. Galaksi Spiral\nMemiliki cakram datar dengan spiral lengan yang terlihat jelas. Biasanya\nmemiliki inti yang padat dan terdiri dari bintang-bintang, gas dan debu.\nBanyak galaksi spiral memiliki lengan spiral yang tampak sangat indah,\nseperti Bima Sakti (galaksi tempat Bumi kita berada).\n"
                 << endl;
            cout << "3. Galaksi Tak Beraturan\nAtau galaksi irregular adalah galaksi yang tidak memiliki bentuk atau\nstruktur yang teratur. Mereka cenderung memiliki tampilan yang acak dan\nkacau dengan banyak gugus bintang dan awan gas yang tersebar di seluruh\ngalaksi. Galaksi irregular sering kali terbentuk melalui interaksi\ngravitasi dengan galaksi lain atau gangguan dari gaya tarik gravitasi.\n"
                 << endl;
            cout << "+-------------------------+" << endl;
            cout << "| JENIS-JENIS GALAKSI     |" << endl;
            cout << "+-------------------------+" << endl;
            cout << "1. Galaksi Andromeda\n2. Galaksi Bima Sakti\n3. Triangulum\n4. Bunga Mawar\n5. Antena dll\n"
                 << endl;
            cout << "+-----------+" << endl;
            cout << "| BINTANG   |" << endl;
            cout << "+-----------+" << endl;
            cout << "Bintang adalah objek astronomi yang memancarkan cahaya dan energi melalui\nreaksi nuklir di intinya. Terbentuk dari awan gas dan debu yang\nmengalami gravitasi, dan memiliki berbagai ukuran, massa, dan warna." << endl;
            cout << endl;
            cout << "+-----------+" << endl;
            cout << "| BULAN     |" << endl;
            cout << "+-----------+" << endl;
            cout << "Bulan adalah satelit alami yang mengorbit sebuah planet, bulan dikenal\nmemiliki suhu rendah dari pada satelit lainnya." << endl;
            cout << endl;

            cout << "0. Keluar" << endl;
            cout << "Apa Anda Ingin Keluar?(0): ";
            cin >> exit;
            if (exit == 0)
            {
                system("CLS");
                goto menu;
            }
        case 2:
            system("CLS");
            {
                Stack stack;

                initStack(stack);

                int choice;
                do
                {
                    cout << "+-------------+" << endl;
                    cout << "| BINTANG     |" << endl;
                    cout << "+-------------+" << endl;
                    cout << "Menu:" << endl;
                    cout << "1. Tambah Bintang" << endl;
                    cout << "2. Hapus Bintang" << endl;
                    cout << "3. Tampilkan Bintang" << endl;
                    cout << "0. Keluar" << endl;
                    cout << "Pilihan Anda: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                    {
                        string zodiak[] = {"Matahari", "Merkurius", "Venus"};
                        int jumlahZodiak = sizeof(zodiak) / sizeof(zodiak[0]);

                        // Memasukkan data dummy zodiak ke dalam stack
                        for (int i = 0; i < jumlahZodiak; i++)
                        {
                            push(stack, zodiak[i]);
                        }

                        cout << "Data berhasil ditambahkan ke dalam stack.\n"
                             << endl;

                        // Meminta pengguna untuk memasukkan data tambahan
                        int dataTambahan;
                        cout << "Masukkan Jumlah Data Bintang Lainnya: ";
                        cin >> dataTambahan;

                        for (int i = 0; i < dataTambahan; i++)
                        {
                            string data;
                            cout << "Masukkan Bintang: ";
                            cin.ignore();
                            getline(cin, data);
                            push(stack, data);
                        }
                        break;
                    }
                    case 2:
                        pop(stack);
                        break;
                    case 3:
                        display(stack);
                        break;
                    case 0:
                    {
                        system("CLS");
                        goto menu;
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                    }
                } while (choice != 0);
            }

            system("CLS");
            break;
        case 3:
            system("CLS");
            Queue queue;
            Stack stack;

            initStack(stack);
            initQueue(queue);
            int choice;
            do
            {
                cout << "+-----------+" << endl;
                cout << "| BULAN     |" << endl;
                cout << "+-----------+" << endl;
                cout << "Menu:" << endl;
                cout << "1. Tambah Bulan" << endl;
                cout << "2. Hapus Bulan" << endl;
                cout << "3. Tampilkan Bulan" << endl;
                cout << "0. Keluar" << endl;
                cout << "Pilihan Anda: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    string nama, jarak, jPlanet;
                    cout << "Nama Bulan: ";
                    cin >> nama;
                    cout << "Suhu Bulan: ";
                    cin >> jarak;

                    enqueue(queue, nama, jarak);
                    cout << "Tambah Data Berhasil" << endl;
                    break;
                }
                case 2:
                {
                    pop(stack);
                    break;
                }
                case 3:
                {
                    cout << endl;
                    displayQueue(queue);
                    break;
                }
                case 0:
                {
                    system("CLS");
                    goto menu;
                    break;
                }
                default:
                    cout << "Pilihan tidak valid." << endl;
                    break;
                }
            } while (choice != 0);

            return 0;
        }
    case 4:
        system("CLS");
        {
            tambahBelakang("100", " 2537 juta", "Andromeda");
            tambahBelakang("200", " 29,3 juta", "Sombrero");
            tambahBelakang("300", "   13 juta", "Centaurus A");
            int subPilihan;

        subPilihan:
            cout << "+-----------------------------------------+" << endl;
            cout << "| JENIS GALAKSI                           |" << endl;
            cout << "+-----------------------------------------+" << endl;
            cout << "|1.  TAMBAH                               |" << endl;
            cout << "|2.  UBAH                                 |" << endl;
            cout << "|3.  HAPUS                                |" << endl;
            cout << "|4.  TAMPILKAN                            |" << endl;
            cout << "|0.  KELUAR                               |" << endl;
            cout << "+-----------------------------------------+" << endl;
            cout << "Masukan Pilihan Anda: ";
            cin >> subPilihan;

            switch (subPilihan)
            {
            case 1:
            {
                Galaksi *bantu = new Galaksi;

                cin.ignore();
                cout << "\n+-----------------------------------------+" << endl;
                cout << "|  TAMBAH BELAKANG                        |" << endl;
                cout << "+-----------------------------------------+" << endl;
                cout << "Masukkan Nama Galaksi               : ";
                getline(cin, bantu->nama);
                cout << "Masukkan Jarak Galaksi Dengan Bumi  : ";
                getline(cin, bantu->jarak);
                cout << "Masukkan Jumlah Planet              : ";
                cin >> bantu->jPlanet;
                cout << "+-----------------------------------------+" << endl;
                tambahBelakang(bantu->jPlanet, bantu->jarak, bantu->nama);
                cout << "\nGalaksi telah ditambahkan di bagian belakang daftar galaksi.\n\n";
                cout << endl;
                goto subPilihan;
                break;
            }

            case 2:
            {
                cout << "\n+-----------------------------------------+" << endl;
                cout << "|  UBAH TENGAH                            |" << endl;
                cout << "+-----------------------------------------+" << endl;
                cout << "\n\nMasukkan Jarak Galaksi Dengan Bumi\t: ";
                cin.ignore();
                getline(cin, jarak);
                cout << "Masukkan Nama Galaksi\t: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Jumlah Planet\t: ";
                cin >> jPlanet;
                cout << "Masukan Posisi\t: ";
                cin >> posisi;
                cout << "+-----------------------------------------+" << endl;
                ubahTengah(jPlanet, jarak, nama, posisi);
                cout << endl;
                goto subPilihan;
                break;
            }

            case 3:
            {
                cout << "\n+-----------------------------------------+" << endl;
                cout << "|  HAPUS TENGAH                           |" << endl;
                cout << "+-----------------------------------------+" << endl;
                cout << "\n\nMasukan Posisi\t: ";
                cin >> posisi;
                hapusTengah(posisi);
                cout << "+-----------------------------------------+" << endl;
                cout << endl;
                goto subPilihan;
                break;
            }
            case 4:
            {
                tampil();
                cout << endl;
                goto subPilihan;
                break;
            }
            case 0:
            {
                goto menu;
                break;
            }
            default:
                break;
            }
            break;
        }
    case 5:
        system("CLS");
        {
            cout << "Masukkan jumlah simpul (maksimal " << maxSimpul << "): ";
            cin >> imelda_2211102001;
            if (imelda_2211102001 > maxSimpul || imelda_2211102001 < 2)
            {
                cout << "Jumlah simpul tidak valid!" << endl;
                return 0;
            }
            cout << "Masukkan nama simpul:" << endl;
            for (int i = 0; i < imelda_2211102001; i++)
            {
                cout << "Simpul " << i + 1 << ": ";
                cin >> simpul[i];
            }
            cout << "Masukkan nilai busur antar simpul:" << endl;
            for (int baris = 0; baris < imelda_2211102001;
                 baris++)
            {
                for (int kolom = 0; kolom < imelda_2211102001;
                     kolom++)
                {
                    cout << simpul[baris] << " --> " << simpul[kolom] << " : ";
                    cin >> busur[baris][kolom];
                }
            }
            tampilGraph();
            return 0;
        }
    case 0:
        return 0;
    default:
        break;
    }
    return 0;
}