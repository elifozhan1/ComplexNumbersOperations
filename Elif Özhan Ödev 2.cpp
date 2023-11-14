/******************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** PROGRAMLAMAYA GİRİŞ DERSİ
**
** ÖDEV NUMARASI: 2
** ÖĞRENCİ ADI: ELİF ÖZHAN
** ÖĞRENCİ NUMARASI: B221210001
** DERS GRUBU: B
******************************/

/* Kütüphaneler */
#include <iostream>
#include <math.h>
#include <locale.h>

/* İsim uzayı */
using namespace std;

/* Karmaşık sayılar sınıfı */
class KarmasikSayi
{
private:

    float reel; /* Sayının gerçek kısmı */
    float img; /* Sayının sanal kısmı */

public:

    /* Karmaşık sayı sınıfı yapıcı fonksiyonu */
    KarmasikSayi() : reel(0), img(0) { }

    /* Sayıyı kullanıcıdan alan metod */
    void SayiAlma()
    {
        cout << "z = a + bi formatında bir karmaşık sayı için; " << endl;
        cout << "Reel a değeri: " << endl;
        cin >> reel;
        cout << "İmajiner b değeri: " << endl;
        cin >> img;

    }

    /* Sonucu ekrana yazdıran metod */
    void EkranaYazdirma()
    {
        cout << "Sonuç: " << reel << " + " << img << "i" << endl;
    }

    /* İşlemler için operatör aşırı yükleme fonksiyonları */
    KarmasikSayi operator + (KarmasikSayi z)
    {
        KarmasikSayi toplam; /* Sonucu atamak için toplam değişkeni */
        toplam.reel = z.reel + reel;
        toplam.img = z.img + img;

        return toplam;
    }

    KarmasikSayi operator - (KarmasikSayi z)
    {
        KarmasikSayi fark;  /* Sonucu atamak için fark değişkeni */
        fark.reel = reel - z.reel;
        fark.img = img - z.img;

        return fark;
    }

    KarmasikSayi operator * (KarmasikSayi z)
    {
        KarmasikSayi carpim;  /* Sonucu atamak için çarpım değişkeni */
        carpim.reel = (reel * z.reel) + (img * z.img * (-1));
        carpim.img = (reel * z.img) + (img * z.reel);

        return carpim;
    }

    KarmasikSayi operator / (KarmasikSayi z)
    {
        KarmasikSayi bolum;  /* Sonucu atamak için bölüm değişkeni */
        KarmasikSayi eslenik; /* Bölme işlemini gerçekleştirmek için gerekli olan ikinci karmaşık sayının eşleniği */
        float deger; /* Bu değer karmaşık sayılar bölüm durumundayken eşlenikle çarpma yapıldığında paydada oluşacak olan gerçek ifade içindir */

        eslenik.reel = z.reel;
        eslenik.img = (-1) * z.img;
        deger = (eslenik.reel * z.reel) + (eslenik.img * z.img * (-1));

        bolum.reel = (reel * eslenik.reel) / deger + (img * eslenik.img * (-1)) / deger;
        bolum.img = (reel * eslenik.img) / deger + (img * eslenik.reel) / deger;

        return bolum;
    }

    /* Kutupsal gösterim için metod */
    void KutupsalGosterim(KarmasikSayi z)
    {
        float r = 0; /* Koordinat düzleminde ifade edilen karmaşık sayı vektörünün büyüklüğü */
        float aci = 0; /* Karmaşık sayı vektörünün x ekseni ile yaptığı açı */
        float tan = 0; /* açı için tanjant değeri */

        tan = z.img / z.reel;
        r = sqrt(pow(z.reel, 2) + pow(z.img, 2)); /* pisagor teoremi yardımıyla r'nin hesaplanışı */
        aci = atan(tan) * 180 / 3.14; /* açının tanjant ve arctan fonksiyonu yardımıyla bulunuşu */

        cout << "Kutupsal Gösterim: [" << r << ", " << aci << "]" << endl;
    }

    /* ='li metodlar için this ifadesi */
    KarmasikSayi operator += (KarmasikSayi z)
    {

        this->reel += z.reel;
        this->img += z.img;

        return *this;
    }

    KarmasikSayi operator -= (KarmasikSayi z)
    {

        this->reel -= z.reel;
        this->img -= z.img;

        return *this;
    }

    KarmasikSayi operator *= (KarmasikSayi z)
    {

        this->reel = (reel * z.reel) + (img * z.img * (-1));
        this->img = (reel * z.img) + (img * z.reel);

        return *this;
    }

    KarmasikSayi operator /= (KarmasikSayi z)
    {
        KarmasikSayi eslenik;
        float deger;

        eslenik.reel = z.reel;
        eslenik.img = (-1) * z.img;
        deger = (eslenik.reel * z.reel) + (eslenik.img * z.img * (-1));

        this->reel = (reel * eslenik.reel) / deger + (img * eslenik.img * (-1)) / deger;
        this->img = (reel * eslenik.img) / deger + (img * eslenik.reel) / deger;

        return *this;
    }

};

int main()
{
    setlocale(LC_ALL, "Turkish"); /* Türkçe karakter desteği */

    KarmasikSayi z1; /* Karmaşık sayı sınıfından 1. nesne oluşturulması */
    KarmasikSayi z2; /* Karmaşık sayı sınıfından 2. nesne oluşturulması */
    KarmasikSayi sonuc; /* Karmaşık sayı sınıfından sonuçların ifade edilmesi için sonuç nesnesinin oluşturulması */

    z1.SayiAlma(); /* 1. nesnenin ekrandan okunması */
    z2.SayiAlma(); /* 2. nesnenin ekrandan okunması */

    int devam = 0; /* Programın seçime bağlı olarak çalışmaya devam etmesini
    sağlayan do - while döngüsünün çalışmasının sağlayan devam değişkeni */

    do
    {
        int secim = 0; /* Yapılacak işlem seçimi */

        /* İşlem menüsü */
        cout << endl << "Yapmak istediğiniz işlemi seçiniz." << endl << endl;
        cout << "1) Toplama" << endl;
        cout << "2) Çıkarma" << endl;
        cout << "3) Çarpma" << endl;
        cout << "4) Bölme" << endl;
        cout << "5) Kutupsal Gösterim" << endl;
        cout << "6) Toplam Eşittir" << endl;
        cout << "7) Fark Eşittir" << endl;
        cout << "8) Çarpım Eşittir" << endl;
        cout << "9) Bölü Eşittir" << endl << endl;
        cin >> secim;

        /* if - else if bloğu */
        if (secim == 1)
        {
            sonuc = z1 + z2;
            sonuc.EkranaYazdirma();
        }

        else if (secim == 2)
        {
            sonuc = z1 - z2;
            sonuc.EkranaYazdirma();
        }

        else if (secim == 3)
        {
            sonuc = z1 * z2;
            sonuc.EkranaYazdirma();
        }

        else if (secim == 4)
        {
            sonuc = z1 / z2;
            sonuc.EkranaYazdirma();
        }

        else if (secim == 5)
        {
            z1.KutupsalGosterim(z1);
            z2.KutupsalGosterim(z2);
        }

        else if (secim == 6)
        {
            z1 += z2;
            z1.EkranaYazdirma();
        }

        else if (secim == 7)
        {
            z1 -= z2;
            z1.EkranaYazdirma();
        }

        else if (secim == 8)
        {
            z1 *= z2;
            z1.EkranaYazdirma();
        }

        else if (secim == 9)
        {
            z1 /= z2;
            z1.EkranaYazdirma();
        }

        cout << "Bu sayılarla işlem yapmaya devam etmek ister misiniz? (Evet: 1, Hayır: 0)" << endl;
        cin >> devam;

    } while (devam == 1);

    /* programın çalışmasını sonlandırmak için */
    return 0;
}