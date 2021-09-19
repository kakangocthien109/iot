#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define FILENAME "log.txt"
#define MAXLENGTHFILE 5000

char filestr[MAXLENGTHFILE];

int fileToStr(char *str)
{
    int status;
    FILE *fp = NULL;

    fp = fopen(FILENAME, "r");
    if (fp == NULL)
    {
        printf("File does not exist\n");
        return -1;
    }

    status = fread(str, MAXLENGTHFILE, 1, fp);

  //  printf("Noi dung cua file log.txt: \n%s", str);

    fclose(fp);
    fp = NULL;
    return status;
}

void dem_bantin_gui()
{
    char tempFilestr[MAXLENGTHFILE];
    strcpy(tempFilestr, filestr);
    char *pattern = "\"cmd\":\"set\"";
    char *token = strtok(tempFilestr, "\n"); // Tach tempFilestr theo \n
    int dem_gui = 0;

    while (token != NULL)
    {
        char *xuathien = strstr(token, pattern); // Tra ve dia chi cua pattern trong token.
        if(xuathien != NULL){
            dem_gui++;
            printf("%s\n", token);
        }
        token = strtok(NULL, "\n");
    }
    printf("So ban tin: %d\n", dem_gui);
}

void dem_bantin_gui_thiet_bi()
{
    char tempFilestr[MAXLENGTHFILE];
    strcpy(tempFilestr, filestr);
    char ten_thiet_bi[5] = "";
    printf("Nhap dia chi NWK cua thiet bi:\n");
    scanf("%s", ten_thiet_bi);
    for (int i = 0; i < strlen(ten_thiet_bi); i++)
    {
        ten_thiet_bi[i] = tolower(ten_thiet_bi[i]); // Chuyen thanh chu thuong
    }

    char pattern[12] = "\"cmd\":\"set\"";
    char pattern2[20] = "\"data\":[\"zwave-";

    strcat(pattern2, ten_thiet_bi);
    
    char *token = strtok(tempFilestr, "\n"); // Tach tempFilestr theo \n | Cat ra roi thay dau xuong dong = null

    int dem_gui = 0;

    while (token != NULL)
    {
        char *xuathien = strstr(token, pattern); // Tra ve dia chi cua pattern trong token.
        if(xuathien != NULL){
            char *xuathientb = strstr(token, pattern2); // Tra ve dia chi cua pattern2 trong token
            if(xuathientb != NULL){
                dem_gui++;
                printf("%s\n", token);
            }
        }
        token = strtok(NULL, "\n");
    }
    printf("So ban tin gui di la: %d\n", dem_gui);
}

void so_cong_tac()
{
    char tempFilestr[MAXLENGTHFILE];
    strcpy(tempFilestr, filestr);
    char pattern[12] = "\"cmd\":\"set\"";
    char pattern2[32] = "\"type\":\"switch\",\"data\":[\"zwave-";
    
    char *token = strtok(tempFilestr, "\n"); // Tach tempFilestr theo \n

    char NWK[5] = "";
    char pre_NWK[5] = "";
    char ENDPOINT[2] = "";

    int dem_thietbi = 0;

    while (token != NULL)
    {
        char *xuathien = strstr(token, pattern); // Tra ve dia chi cua pattern trong token.
        if(xuathien != NULL){
            char *xuathientb = strstr(token, pattern2); // Tra ve dia chi cua pattern2 trong token
            if(xuathientb != NULL){
                strncpy(NWK, (xuathientb + 31), 4); // xuathientb+31 do type:switch la 31 ky tu va sau zwave moi co dia chi thiet bi
                if (strcmp(NWK, pre_NWK) != 0)
                {
                    strncpy(pre_NWK, NWK, 4); // pre_NWK bỏ duplicate
                    dem_thietbi++;
                    strncpy(ENDPOINT, (xuathientb + 38), 1);
                    printf("Thiet bi %d co dia chi la: NWK - %s, ENDPOINT - %s\n", dem_thietbi, NWK, ENDPOINT);
                }
            }
        }
        token = strtok(NULL, "\n");
    }
}

void so_ban_tin_loi()
{
    char tempFilestr[MAXLENGTHFILE];
    strcpy(tempFilestr, filestr);
    char pattern[11] = "\"reqid\": \"";

    char *token = strtok(tempFilestr, "\n"); // Tach tempFilestr theo \n

    char reqid_chan[5] = ""; // Cac ban tin gui
    char reqid_le[5] = ""; // Cac ban tin nhan
    int chan = 1;
    int loi = 0;

    while (token != NULL)
    {
        char *xuathien = strstr(token, pattern); // Tra ve dia chi cua pattern trong token.
        if(xuathien != NULL){
            if (chan == 1)
            {
                strncpy(reqid_chan, (xuathien + 10), 4);
                chan = 0; // Ke tiep kt ban tin le
            }
            else
            {
                strncpy(reqid_le, (xuathien + 10), 4);
                chan = 1;
                if (strcmp(reqid_chan, reqid_le) != 0)
                {
                    loi++;
                }
            }
        }
        token = strtok(NULL, "\n");
    }
    printf("So ban tin loi: %d\n", loi);
}

int lay_ngay(int year, int month, int day) { // lay ngay theo Julian Day
    if (month < 3) {
        year--;
        month += 12;
    }
    return 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306; // Lay ngay de so sanh do 2 ban tin gui - nhan co the khac ngay
}

void dotre_lonnhat() // tim do tre lon nhat
{
    char tempFilestr[MAXLENGTHFILE];
    strcpy(tempFilestr, filestr);
    char pattern[11] = "\"reqid\": \"";
    
    char *token = strtok(tempFilestr, "\n"); // Tach tempFilestr theo \n
    
    char reqid_chan[5] = "";
    char reqid_le[5] = "";

    char thoi_gian[23] = "";
    double gui = 0.0f;
    double nhan = 0.0f;
    double max = 0.0f;
    int ngay, thang, nam;
    int layngay_gui, layngay_nhan;
    int gio, phut;
    float giay = 0.0f;
    double tre = 0.0f;

    int chan = 1;
    char temp_nam[5] = "";
    char temp_thang[3] = "";
    char temp_ngay[3] = "";
    char temp_gio[3] = "";
    char temp_phut[3] = "";
    char temp_giay[7] = "";

    while (token != NULL)
    {
            strncpy(thoi_gian, (token + 7), 22);
            strncpy(temp_nam, thoi_gian, 4);
            nam = atoi(temp_nam); // lay nam | atoi chuyen chuoi thanh so nguyen
            strncpy(temp_thang, (thoi_gian + 5), 2);
            thang = atoi(temp_thang);
            strncpy(temp_ngay, (thoi_gian + 8), 2);
            ngay = atoi(temp_ngay);
            strncpy(temp_gio, (thoi_gian + 10), 2);
            gio = atoi(temp_gio);
            strncpy(temp_phut, (thoi_gian + 13), 2);
            phut = atoi(temp_phut);
            strncpy(temp_giay, (thoi_gian + 16), 6);
          //  printf("Giay la: %s\n", temp_giay);
            giay = atof(temp_giay);
           // printf("giay la: %f\n", giay);
            char *xuathien = strstr(token, pattern); // Tra ve dia chi cua pattern trong token.
            if(xuathien != NULL){
                if (chan == 1) // ban tin chan: 0, 2, 4, 6 ...
                {
                    strncpy(reqid_chan, (xuathien + 10), 4);
                    layngay_gui = lay_ngay(nam, thang, ngay);
                    gui = (double)giay + (double)(phut * 60) + (double)(gio * 3600);
                    chan = 0;
                }
                else // ban tin le: 1, 3, 5, ...
                {
                    strncpy(reqid_le, (xuathien + 10), 4);
                    layngay_nhan = lay_ngay(nam, thang, ngay);
                    nhan = (double)giay + (double)(phut * 60) + (double)(gio * 3600);
                    chan = 1;
                    if (strcmp(reqid_chan, reqid_le) == 0) // so sanh ID chan va ID le
                    {
                        tre = nhan - gui + (double)((layngay_nhan - layngay_gui) * 60 * 60 * 24); // Cai truoc so sanh giay, cai sau so sanh ngay
                        max = (tre > max) ? tre : max; // cap nhat lon nhat
                    }
                }
            }
            token = strtok(NULL, "\n");
    }
    printf("Do tre lon nhat la: %d Milisecond\n", (int)(max * 1000));
}

void dotre_trungbinh() // tim do tre trung binh
{
    char tempFilestr[MAXLENGTHFILE];
    strcpy(tempFilestr, filestr);
    char pattern[11] = "\"reqid\": \"";
    
    char *token = strtok(tempFilestr, "\n"); // Tach tempFilestr theo \n
    
    char reqid_chan[5] = "";
    char reqid_le[5] = "";

    char thoi_gian[23] = "";
    double gui = 0.0f;
    double nhan = 0.0f;
    double average = 0.0f;
    int ngay, thang, nam;
    int layngay_gui, layngay_nhan;
    int gio, phut;
    float giay = 0.0f;
    double tre = 0.0f;

    int chan = 1;
    char temp_nam[5] = "";
    char temp_thang[3] = "";
    char temp_ngay[3] = "";
    char temp_gio[3] = "";
    char temp_phut[3] = "";
    char temp_giay[7] = "";
    int thanhcong = 0; // dem so ban tin thanh cong
    
    while (token != NULL)
    {
            strncpy(thoi_gian, (token + 7), 22);
            strncpy(temp_nam, thoi_gian, 4);
            nam = atoi(temp_nam); // lay nam
            strncpy(temp_thang, (thoi_gian + 5), 2);
            thang = atoi(temp_thang);
            strncpy(temp_ngay, (thoi_gian + 8), 2);
            ngay = atoi(temp_ngay);
            strncpy(temp_gio, (thoi_gian + 10), 2);
            gio = atoi(temp_gio);
            strncpy(temp_phut, (thoi_gian + 13), 2);
            phut = atoi(temp_phut);
            strncpy(temp_giay, (thoi_gian + 16), 6);
            giay = atof(temp_giay);
            char *xuathien = strstr(token, pattern); // Tra ve dia chi cua pattern trong token.
            if(xuathien != NULL){
                if (chan == 1)
                {
                    strncpy(reqid_chan, (xuathien + 10), 4); //lay ID chan
                    layngay_gui = lay_ngay(nam, thang, ngay);
                    gui = (double)giay + (double)(phut * 60) + (double)(gio * 3600);
                    chan = 0;
                }
                else
                {
                    strncpy(reqid_le, (xuathien + 10), 4); // lay ID le
                    layngay_nhan = lay_ngay(nam, thang, ngay);
                    nhan = (double)giay + (double)(phut * 60) + (double)(gio * 3600);
                    chan = 1;
                    if (strcmp(reqid_chan, reqid_le) == 0) // so sanh ID chan va le
                    {
                        thanhcong++;
                        tre = nhan - gui + (double)((layngay_nhan - layngay_gui) * 60 * 60 * 24);
                        average = average + tre; // lay tong cac do tre
                    }
                }
            }
            token = strtok(NULL, "\n");
    }
    average = average / thanhcong; // Lay gia tri trung binh thuc su
    printf("Do tre trung binh la: %d Milisecond\n", (int)(average * 1000));
}

int main()
{
    fileToStr(filestr);         // lay noi dung file log.txt dua vao filestr
    dem_bantin_gui();           // dem so ban tin gui di
    dem_bantin_gui_thiet_bi();  // dem so ban tin gui di theo thiet bi
    so_cong_tac();              // dem so cong tac theo NWK va ENDPOINT
    so_ban_tin_loi();           // dem so ban tin loi
    dotre_lonnhat();            // tim do tre lon nhat
    dotre_trungbinh();          // tim do tre trung binh
    return 0;
}