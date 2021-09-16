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

    printf("Noi dung cua file log.txt: \n%s", str);

    fclose(fp);
    fp = NULL;
    return status;
}

void dem_bantin_gui()
{
    char *pattern = "\"cmd\":\"set\"";
    char *xuathien = strstr(filestr, pattern); // Tra ve dia chi cua pattern trong filestr.
    int dem_gui;

    while (xuathien != NULL)
    {
        dem_gui++;
        xuathien = strstr((xuathien + 11), pattern);
    }
    printf("So ban tin gui di la: %d\n", dem_gui);
}

void dem_bantin_gui_thiet_bi()
{
    char ten_thiet_bi[5];
    scanf("%s", ten_thiet_bi);
    for (int i = 0; i < strlen(ten_thiet_bi); i++)
    {
        ten_thiet_bi[i] = tolower(ten_thiet_bi[i]);
    }

    char pattern[12] = "\"cmd\":\"set\"";
    char pattern2[17] = "\"data\":[\"zwave-";

    strcat(pattern2, ten_thiet_bi);

    char *xuathien = strstr(filestr, pattern); // Tra ve dia chi cua pattern trong filestr.
    xuathien = strstr(xuathien, pattern2);

    int dem_gui;

    while (xuathien != NULL)
    {
        dem_gui++;
        xuathien = strstr((xuathien + 19), pattern2);
    }
    printf("So ban tin gui di theo thiet bi %s la: %d\n", ten_thiet_bi, dem_gui);
}

void so_cong_tac()
{

    char pattern[12] = "\"cmd\":\"set\"";
    char pattern2[32] = "\"type\":\"switch\",\"data\":[\"zwave-";

    char *xuathien = strstr(filestr, pattern); // Tra ve dia chi cua pattern trong filestr.
    xuathien = strstr(xuathien, pattern2);

    char NWK[5] = "";
    char pre_NWK[5] = "";
    char ENDPOINT[2] = "";

    int dem_thietbi = 0;

    while (xuathien != NULL)
    {
        strncpy(NWK, (xuathien + 31), 4);
        if (strcmp(NWK, pre_NWK) != 0)
        {
            strncpy(pre_NWK, NWK, 4);
            dem_thietbi++;
            strncpy(ENDPOINT, (xuathien + 38), 1);
            printf("Thiet bi %d co dia chi la: NWK - %s, ENDPOINT - %s\n", dem_thietbi, NWK, ENDPOINT);
        }
        xuathien = strstr((xuathien + 39), pattern2);
    }
}

void so_ban_tin_loi()
{

    char pattern[12] = "\"cmd\":\"set\"";
    char pattern2[11] = "\"reqid\": \"";

    char *xuathien = strstr(filestr, pattern); // Tra ve dia chi cua pattern trong filestr.
    xuathien = strstr(xuathien, pattern2);

    char reqid_chan[5] = "";
    char reqid_le[5] = "";
    int chan = 1;
    int loi = 0;

    while (xuathien != NULL)
    {
        if (chan == 1)
        {
            strncpy(reqid_chan, (xuathien + 10), 4);
            chan = 0;
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
        xuathien = strstr((xuathien + 14), pattern2);
    }
    printf("So ban tinh loi la: %d\n", loi);
}

void dotre()
{
    so_ban_tin_loi();
    char pattern[8] = "[INFO][";

    char *xuathien = strstr(filestr, pattern); // Tra ve dia chi cua pattern trong filestr.

    char thoi_gian[23] = "";
    double gui = 0.0f;
    double nhan = 0.0f;
    int ngay, thang, nam;
    int gio, phut;
    float giay = 0.0f;
    float tre = 0.0f;

    int chan = 1;
    char temp_nam[5];
    char temp_thang[3];
    char temp_ngay[3];
    char temp_gio[3];
    char temp_phut[3];
    char temp_giay[7];
    double max = 0.0f;

    while (xuathien != NULL)
    {
        strncpy(thoi_gian, (xuathien + 7), 22);
        strncpy(temp_nam, thoi_gian, 4);
        nam = atoi(temp_nam);
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

        if (chan == 1)
        {
            gui = (double)giay + (double)(phut * 60) + (double)(gio * 360);
            chan = 0;
        }
        else
        {
            nhan = (double)giay + (double)(phut * 60) + (double)(gio * 360);
            chan = 1;
            tre = nhan - gui;
            max = (tre > max) ? tre : max;
        }

        xuathien = strstr((xuathien + 30), pattern);
    }
    printf("Do tre lon nhat la: %lg millisecond\n", max * 1000);
}


void tinh_trung_binh()
{

    char pattern[8] = "[INFO][";

    char *xuathien = strstr(filestr, pattern); // Tra ve dia chi cua pattern trong filestr.

    char thoi_gian[23] = "";
    double gui = 0.0f;
    double nhan = 0.0f;
    int ngay, thang, nam;
    int gio, phut;
    float giay = 0.0f;
    float tre = 0.0f;

    int chan = 1;
    char temp_nam[5];
    char temp_thang[3];
    char temp_ngay[3];
    char temp_gio[3];
    char temp_phut[3];
    char temp_giay[7];
    double max = 0.0f;

    while (xuathien != NULL)
    {
        strncpy(thoi_gian, (xuathien + 7), 22);
        strncpy(temp_nam, thoi_gian, 4);
        nam = atoi(temp_nam);
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

        if (chan == 1)
        {
            gui = (double)giay + (double)(phut * 60) + (double)(gio * 360);
            chan = 0;
        }
        else
        {
            nhan = (double)giay + (double)(phut * 60) + (double)(gio * 360);
            chan = 1;
            tre = nhan - gui;
            max = (tre > max) ? tre : max;
        }

        xuathien = strstr((xuathien + 30), pattern);
    }
    printf("Do tre lon nhat la: %lg millisecond\n", max * 1000);
}

int main()
{
    fileToStr(filestr);
    // dem_bantin_gui();
    // dem_bantin_gui_thiet_bi();
    // so_cong_tac();
    // so_ban_tin_loi();
    dotre();
    return 0;
}