#include <stdio.h>
#include <string.h>
#include <windows.h >
#include <conio.h>
#include <stdlib.h>

//===================================== HIEU UNG XOA VA VIET KI TU (1,2) ======================================
void in_giua(){
	for(int i=0;i<10;i++){
	printf("\n");
	}
	for(int i=0;i<10;i++){
	printf("    ");
	}
}
void xoa (){
	system("cls");//xoa man hinh
}
void cham(int ms){
	Sleep(ms); // cham lai bao nhieu mili giay
}
void datmau(int mau){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mau);//dat mau cho chu
}
	
// HIEU UNG XOA KI TU (1)
void giam(char *s){
	int mau=1;
	int dodai=strlen(s);
	while(1){
	xoa();
        if(kbhit()){
            char c = getch();
            if(c == 'c') break;
            if(c == 'x') exit(0); 
			 }
	for(int i=dodai;i>=0;i--){//in giam dan
		xoa();
		datmau(mau);
		in_giua();
		for(int k=0;k<=i;k++){
			printf("%c",s[k]);
		}
		int t=0;
		if(i==dodai-1) {// in het chuoi thi nhap nhap doi mau 7 lan 
			while(t<7){
				xoa();
				datmau(mau);
				in_giua();	
				printf("%s",s);
				cham(500);
				mau++;
				if(mau>15)mau=1;
				t++;		
			}
		}
		cham(100);
		mau++;
		if(mau>15) mau=1;
		}
	}
}

// HIEU UNG VIET KI TU (2)
void tang(char *s){
	int mau=1;
	int dodai=strlen(s);
	while(1){
		if(kbhit()) {
			char c = getch();
			if(c == 'c') { xoa(); break; }
			if(c == 'x') exit(0);
	}
	for (int i=0; i<dodai ;i++) {//in tang dan 
		xoa();
		datmau(mau);
		in_giua();
		for(int k=0;k<=i;k++){
			printf("%c",s[k]);
		}
		int t=0;
		if(i==dodai-1){// in het chuoi thi nhap nhay doi mau 7 lan  
			while(t<7){
				xoa();
				datmau(mau);
				in_giua();
				printf("%s",s);
				cham(500);
				mau++;
				if(mau>15)mau=1;
				t++;
				
			}
		}
		cham(100); 
		mau++; 
		if(mau>15)mau=1;// den 15 thi reset lai
	}
}
	}

// ===================================== HIEU UNG BUNG KI TU VA BAY KI TU (3, 4) ====================================

// HIEU UNG BUNG KI TU (3)
//Dieu khien con tro
	void gotoxy(int x, int y) {
		COORD vi_tri = {x, y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), vi_tri);
	}   
//Tao hieu ung
	void hieu_ung_bung(char *chuoi) {
	// Lay kich thuoc console
	    CONSOLE_SCREEN_BUFFER_INFO console;
	    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console);
	    int rong = console.srWindow.Right - console.srWindow.Left + 1;
	    int cao = console.srWindow.Bottom - console.srWindow.Top + 1;
	//Khoi tao gia tri
	    int do_dai = strlen(chuoi);
	    int trung_tam = do_dai / 2;
	    int bang_mau[] = {12, 14, 15, 9};
	    while(1){
		// An con tro
			CONSOLE_CURSOR_INFO con_tro = {1, FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &con_tro);	
    	// Bung ra
        	for (int i = 0; i <= trung_tam; i++) {
            	system("cls");
            	char hien_thi[100] = {0};
            	for (int j = trung_tam - i; j <= trung_tam + i && j < do_dai; j++) {
                	if (j >= 0) hien_thi[j - (trung_tam - i)] = chuoi[j];
            	}
            	gotoxy((rong - strlen(hien_thi)) / 2, cao / 2);
            	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bang_mau[i % 4]);
            	printf("%s", hien_thi);
            	Sleep(150);
        	}
        // Thu lai
        	for (int i = trung_tam; i >= 0; i--) {
            	system("cls");
            	char hien_thi[100] = {0};
            	for (int j = trung_tam - i; j <= trung_tam + i && j < do_dai; j++) {
                	if (j >= 0) hien_thi[j - (trung_tam - i)] = chuoi[j];
            	}
            	gotoxy((rong - strlen(hien_thi)) / 2, cao / 2);
            	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bang_mau[i % 4]);
            	printf("%s", hien_thi);
            	Sleep(150);
        	}
    	}
	}
// HIEU UNG BAY KI TU (4)
//Ve ki tu va ve mau
	void ve_ki_tu(int x, int y, char c, int mau) {
	    gotoxy(x, y);
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mau);
	    putchar(c);
	}
void hieu_ung_bay (char*s){
//Khoi tao
int do_dai = strlen(s); int bang_mau[] = {12, 14, 15, 9}; 
//Can giua console  
    int giua_x = 40; int giua_y = 12;
//Tao hieu ung
    while (1) {    	
    //Lap tung ki tu
        for (int i = 0; i < do_dai; i++) {
            system("cls");            
    // In cac ky tu bay xong
        	for (int j = 0; j < i; j++) {
                ve_ki_tu(giua_x + j, giua_y, s[j], bang_mau[j % 4]);
            }        
    // Hieu ung ki tu bay vao
            for (int so_lan = 0; so_lan < 10; so_lan++) {
                int x_hien_tai = (giua_x + i) * so_lan / 10; // Bay tu ben trai
                int y_hien_tai = giua_y - (5 - so_lan/2); // Bay tu ben tren           
    		//Xoa vi tri cu
        		if (so_lan > 0) {
            		int x_cu = (giua_x + i) * (so_lan-1) / 10;
            		int y_cu = giua_y - (5 - (so_lan-1)/2);
            		gotoxy(x_cu, y_cu);putchar(' ');
            	}
    		//Ve ky tu o vi tri moi
        		ve_ki_tu(x_hien_tai, y_hien_tai, s[i], bang_mau[i % 4]);
        		Sleep(30);
        	}
    	}
    //Hien chuoi trong 2 giay
        system("cls");
        for (int i = 0; i < do_dai; i++) {
            ve_ki_tu(giua_x + i, giua_y, s[i], bang_mau[i % 4]);
        }
        Sleep(2000);
    }
}
//==========================HIEU UNG DI CHUYEN QUA LAI & NHAP NHAY===============================

#define MAX_LINES 100
#define MAX_WIDTH 100
//ham ghi khoang trong truoc phan tu trong mang
void addLeadingSpace(char *s, int *len) {
    int i;
	for (i = *len; i >= 0; i--) {
        s[i + 1] = s[i];
    }
    s[0] = ' ';
    (*len)++;
}
//ham xoa khoang trong truoc phan tu mang
void removeLeadingSpace(char *s, int *len) {
    int i;
	if (s[0] == ' ') {
        for (i = 0; i <= *len; i++) {
            s[i] = s[i + 1];
        }
        (*len)--;
    }
}

//ham hieu ung ky tu di chuyen qua lai
int di_chuyen(){
	int i;//bien lap
    char text[MAX_LINES][MAX_WIDTH * 2] = {0};//mang luu tru chuoi ky tu tu file
    int len[MAX_LINES] = {0};//bien luu tru do dai chuoi ky tu trong mang text
    int originalLen[MAX_LINES] = {0};//bien luu tru do dai goc cua chuoi ky tu trong mang text
    int phase[MAX_LINES] = {0}; // trang thai di chuyen 0 = tien, 1 = lui
	//mo file text.txt
    FILE *f = fopen("text.txt", "r");
    if (f == NULL) {
//        printf("Khong the mo file text.txt\n");//bao loi neu khong mo duoc file
		return 1;
    }
	//ghi chuoi ky tu tu file text.txt vao mang text
    while (i < MAX_LINES && fgets(text[i], MAX_WIDTH, f)) {
        len[i] = strlen(text[i]);//tinh do dai tung dong chuoi ky tu vua ghi tu file
        originalLen[i] = len[i];//ghi lai do dai goc thuc te cua chuoi ky tu (khong co \n)
        i++;
    }
    fclose(f);
    int lines = i;
	//hieu ung di chuyen
    while (!kbhit()) {

        system("cls");//xoa cac ky tu tren man hinh
    	printf("bam mhim bat ki de ket thuc\n\n\n");
        //in va cap nhat vi tri tung dong
        for (i = 0; i < lines; i++) {
            printf("%s\n", text[i]);//in cac chuoi ky tu trong file len man hinh

            if (phase[i] == 0) {
                if (len[i] < MAX_WIDTH) {
                    addLeadingSpace(text[i], &len[i]);//di chuyen chuoi ky tu qua phai
                } else {
                    phase[i] = 1;//doi huong khi do dai cua chuoi ky tu trong mang dat MAX_LENTH
                }
            } else {
                if (len[i] > originalLen[i]) {
                    removeLeadingSpace(text[i], &len[i]);//di chuyen chuoi ky tu qua trai
                } else {
                    phase[i] = 0;//doi huong khi chuoi ky tu tro ve do dai goc originallen
                }
            }
        }
        Sleep(100);//van toc cho cac chuoi ky tu chay
    }
    getch();
}

//ham hieu ung chuoi ky tu nhap nhay nhap nhay
int nhap_nhay(){
	int i = 0;
    char text[MAX_LINES][MAX_WIDTH];

    //mo file text.txt
    FILE* f = fopen("text.txt", "r");
    if (f == NULL) {
        return 1;
    }

    while (i < MAX_LINES && fgets(text[i], MAX_WIDTH, f) != NULL) {
        text[i][strcspn(text[i], "\n")] = '\0'; //xoa \n trong chuoi ky tu
        i++;
    }
    fclose(f);

    int lines = i;//bien luu so luong dong
	int k;
	int t;
    while (!kbhit()) {
        //hien thi tung dong tu tren xuong duoi
        for (k = 0; k < lines; k++) {
            system("cls");
            //in lan luot cac dong
            for (i = 0; i <= k; i++) {
                printf("%s\n",text[i]);
            }

            Sleep(300);
        }

        //cho cac dong nhap nhay 3 lan
        for (t = 0; t < 3; t++) {
            system("cls");
            Sleep(200);;
            for (i = 0; i < lines; i++) {
                printf("%s\n",text[i]);
            }
            Sleep(200);
        }

        Sleep(500);
    }
	getch();
	
}

//==========================QUAY LAI MENU VA THOAT MENU (HAM CHUNG)==================
int quay_thoat_menu(){
	if(kbhit()){
		char c = getch();
		if (c=='c') return 1;
		if (c='x')	exit(0);
	} return 0;
}
//=================================== MAIN ===================================================
int main(){ 
    FILE *f;
    char s[100];
    f = fopen("du lieu.txt","r");
    fgets(s, sizeof(s), f);
    fclose(f);
    s[strcspn(s,"\n")] = '\0'; // bo \n neu co
    
//=================================== MENU HIEU UNG ==========================================
	while(1) {
	system("cls");
	printf("\n\n\n\n\n\n\n");	printf("\t\t\t\t");
    printf("================ MENU CAC HIEU UNG ================\n\t\t\t\t");
    printf("1. HIEU UNG 1 (Viet Ki Tu & Xoa Ki Tu)\n\t\t\t\t");
    printf("2. HIEU UNG 2 (Bung Ki Tu & BAY KI TU) \n\t\t\t\t");
    printf("3. \n\t\t\t\t");
    printf("4. \n\t\t\t\t");
    printf("5. \n\t\t\t\t");
    printf("6. \n\t\t\t\t");
    printf("7. \n\t\t\t\t");
    printf("8. \n\t\t\t\t");
    printf("0. \n\t\t\t\t");
    printf("X. Thoat chuong trinh\n\t\t\t\t");
    printf("==================================================\n"); printf("\t\t\t\t");
    printf("---> Moi ban lua chon:(1-2-3-4-5-6-7-8):");
    char nhap[20]; scanf("%s",nhap);
	if(strcmp(nhap,"x")==0) exit(0);
	int chon = atoi(nhap);
	//Chon sai so thi out
	if(chon < 0 || chon > 8){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n");	printf("\t\t\t\t\t");
		printf("\tVui Long chon lai\n\t\t\t\t\t");
		printf("An phim bat ky de quay ve menu.....");
		getch();
		continue;
	}
//=================================== LUA CHON HIEU UNG =======================================
    	switch(chon) {
        	case 1:
            	tang(s);
            	giam(s);
            	if(quay_thoat_menu() ==1) break;
				break;
        	case 2:
            	hieu_ung_bung(s);
            	hieu_ung_bay(s);
            	if(quay_thoat_menu() ==1) break;
				break;	
		}
	}
	return 0;
}


