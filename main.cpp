#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#define WINDOW_WIDTH 1366 //pendefinisian ukuran width window saat dirun
#define WINDOW_HEIGHT 700 //pendefinisian ukuran height window saat dirun
#include "math.h"
float kecepatan1 = 0.1f;
float kecepatanX = -1.0f;
float kecepatanY = 0.8f;
int scorep1 = 0;
int scorep2 = 0;
bool mvUp = false;
bool mvDown = false;
bool up = false;
bool down = false;
bool demo = true;
bool menuu = true;
bool first = true;
bool easy = false;
bool medium = false;
bool hard = false;
bool abot = false;
bool pilihlvl = false;
bool Over = false;
bool loadingg = false;
int loadingtime = 0;
int waktu = 60;

float batas [] = {-600,600,-300,50};
//float batas5[] = {-1150,80,-90,90};
//float batas1[] = {-80,1150,-90,90};
//               xmin, xmax, ymin, ymax
float chara[] = {-30.5f, 30.5f, -30.5f, 30.5f, -550.0f, -200.1f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f};

float bot[] = {-30.5f, 30.5f, -30.5f, 30.5f, 550.0f, -200.1f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f};
// X1, X2, Y1, Y2, TRANSLATE X, TRANSLATE Y, TRANSLATE Z, isKanan, RelativeKiri, Relative Kanan;
float ball[] = {-30.5f, 30.5f, -30.5f, 30.5f, 0.1f, -200.1f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
// X1, X2, Y1, Y2, TRANSLATE X, TRANSLATE Y, TRANSLATE Z, isKanan, RelativeKiri, RelativeKanan, relative bawah, relative atas;
float panahpilih[] = {-20.0f, 20.0f, -20.0f, 20.0f, 0.0f, 0.0f};

const double PI = 3.141592653589793;
int i;
int win_width, win_height; //inisialisasi variabel untuk proses responsive
bool play = false;

void displayText(int x, int y, int r, int g, int b, const char *string ) {
         float x1 = x;
         float y1 = y;
	int j = strlen( string );

	glColor3f( r, g, b );
	glRasterPos2f( x1, y1 );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
	}
}

void Keterangan(int x, int y, int r, int g, int b, const char *string ) {
         float x1 = x;
         float y1 = y;
	int j = strlen( string );

	glColor3f( r, g, b );
	glRasterPos2f( x1, y1 );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, string[i] );
	}
}



void time () {

char times[100]={"0"};

sprintf(times,"%i",waktu); //konversi time ke label

displayText(0,300,0,0,0,times);

}


void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {

    glBegin(GL_POLYGON);
 for (i=0;i<=360;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
  glVertex2f(x,y);
 }
 glEnd();


}

void matahari() {
    glPushMatrix();
    glColor3ub(245,235,103);
lingkaran(2,99,0,0);
glPopMatrix();
}

void kotak () {
    glPushMatrix();
glBegin(GL_POLYGON);
glVertex2f(-0.1,-0.1);
glVertex2f(0.1,-0.1);
glVertex2f(0.1,0.1);
glVertex2f(-0.1,0.1);
glEnd();
glPopMatrix();
}

void pembatas (){
    glPushMatrix();
    glColor3ub(0,0,0);
glBegin(GL_LINES);
glVertex2f(1,200);
glVertex2f(1,-200);
glEnd();
glPopMatrix();
}

void gunung () {
    glPushMatrix();
    glScaled(1.2,1,1);
    glTranslated(0,-1,0);
    glColor3ub(1,50,108);

glBegin(GL_POLYGON);
glVertex2f(-2.78,3.53);
glColor3ub(23,118,202);
glVertex2f (-7,-1);
glVertex2f (1,-1);
glEnd();
glPopMatrix();

}

void rumput() {
       glPushMatrix();
    glTranslated(-1,0.8,0);
    glScaled(1.27,2,1);
glPushMatrix();
		glColor3ub(155,185,1);
    glBegin(GL_POLYGON);
glVertex2f	(0.8920992831176,-2.2424716389521)	;
glVertex2f	(0.8454485450967,-0.7403178746767)	;
glVertex2f	(0.3136301316576,-0.7496480222809)	;
glVertex2f	(0.1736779175946,-2.2238113437437)	;
		glEnd();

		glBegin(GL_POLYGON);
glVertex2f	(-1.3471361418891,-2.2238113437437)	;
glVertex2f	(-0.9179493520961,-0.7403178746767)	;
glVertex2f	(-2.1681891310582,-0.7309877270725)	;
glVertex2f	(-2.9146009393938,-2.2144811961395)	;
		glEnd();

		glBegin(GL_POLYGON);
glVertex2f	(-4.4634054416901,-2.2144811961395)	;
glVertex2f	(-3.3558155522208,-0.7435028077278)	;
glVertex2f	(-4.6197830155225,-0.7078354996627)	;
glVertex2f	(-6.0129493058709,-2.2953970863387)	;
glEnd();
		glPopMatrix();
		glPushMatrix();
		glColor3ub(100,141,1);
		glBegin(GL_POLYGON);
glVertex2f	(0.3136301316576,-0.7496480222809)	;
glVertex2f	(0.1736779175946,-2.2238113437437)	;
glVertex2f	(-1.3471361418891,-2.2238113437437)	;
glVertex2f	(-0.9179493520961,-0.7403178746767)	;
		glEnd();

		glBegin(GL_POLYGON);
glVertex2f	(-2.1681891310582,-0.7309877270725)	;
glVertex2f	(-2.9146009393938,-2.2144811961395)	;
glVertex2f	(-4.4634054416901,-2.2144811961395)	;
glVertex2f	(-3.3558155522208,-0.7435028077278)	;
		glEnd();
		glPopMatrix();
		glPopMatrix();
}

void marka () {
glPushMatrix();
glTranslated(-55,-9,0);
glScaled(20,3.5,1);
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f	(0.4258811780087, -5.5043196314873)	;
glVertex2f	(2.8397014433283, -5.5049674436726)	;
glVertex2f	(2.8537333738927, -8.9919021889268)	;
glVertex2f	(0.21937959908, -9.001813937376)	;
glEnd();

glBegin(GL_POLYGON);
glVertex2f	(-7.4016695128786, -5.5388363735447)	;
glVertex2f	(-0.8099866337159, -5.5039879538396)	;
glVertex2f	(-1.0000000870766, -9.0017533804051)	;
glVertex2f	(-8.0000000698123, -9.0014057456196)	;
glEnd();

glBegin(GL_POLYGON);
glVertex2f	(-15.2828400173216, -5.5001037827969)	;
glVertex2f	(-8.5449841661359, -5.5472049241816)	;
glVertex2f	(-9.1564041540576, -9.00134831615)	;
glVertex2f	(-16.3956362118274, -9.0009888005944)	;
glEnd();

glBegin(GL_POLYGON);
glVertex2f	(-22.7349713665577, -5.4981038072547)	;
glVertex2f	(-16.3860533953886, -5.5617079996628)	;
glVertex2f	(-17.3908383560256, -9.0009393767537)	;
glVertex2f	(-24.4353711667748, -9.0005895303739)	;
glEnd();

glBegin(GL_POLYGON);
glVertex2f	(-29.4982241295091, -5.4962887104083)	;
glVertex2f	(-23.8503092600516, -5.5396154580579)	;
glVertex2f	(-25.4787711927344, -9.055025344484)	;
glVertex2f	(-30.3124597865708, -9.042101043431)	;
glEnd();
glPopMatrix();
}

void aspal () {
    glPushMatrix();
    glTranslated(0,-0.4,0);
    glScaled(70,3.5,1);
    glColor3ub(125,125,125);
    kotak();
    glPopMatrix();

}

void garisLapangan() {
    glPushMatrix();

    glTranslated(-1.15,2.9,0);
    glScaled(0.62,1.5,0);
    glColor3ub(255,255,255);
glBegin(GL_LINE_LOOP);

glVertex2f	(-8.8333092501388,-3.858709287527)	;
glVertex2f	 (-2.9857805713419,-3.8488317052993)	;
glVertex2f	(1.8443571380023,-3.8784644519824)	;
glVertex2f	(1.8442650290481,-3.6797308729377)	;
glVertex2f	(1.8443571380023,-3.5129939095575)	;
glVertex2f	(1.4985958710907,-3.5133808028734)	;
glVertex2f	(1.2106094945098,-3.5109607492887)	;
glVertex2f	(0.8968343883175,-3.5003347814612)	;
glVertex2f	(0.5523549194677,-3.4795000526875)	;
glVertex2f	(0.2518220232773,-3.4555705163796)	;
glVertex2f	(-0.0432151783973,-3.4230146872293)	;
glVertex2f	(-0.2344806746553,-3.3945283367228)	;
glVertex2f	 (-0.4092747596984,-3.3635948352908)	;
glVertex2f	(-0.5112742036867,-3.3362735556511)	;
glVertex2f	(-0.5823095307501,-3.2907380895848)	;
glVertex2f	 (-0.5895952053207,-3.2397383675906)	;
glVertex2f	 (-0.5604525070383,-3.196024320167)	;
glVertex2f	 (-0.4905490979924,-3.1649877211035)	;
glVertex2f	 (-0.4220246901969,-3.1504888541008)	;
glVertex2f	(-0.3163824089232,-3.1359175049596)	;
glVertex2f	(-0.2380614072893,-3.1177033185331)	;
glVertex2f	(-0.1142049395891,-3.0958462948213)	;
glVertex2f	(-0.026776844742,-3.0830963643228)	;
glVertex2f	 (0.1080081348141,-3.0721678524669)	;
glVertex2f	 (0.2300431838716,-3.0648821778963)	;
glVertex2f	 (0.3393283024306,-3.0648821778963)	;
glVertex2f	(0.4303992345631,-3.0648821778963)	;
glVertex2f	(0.5196487480529,-3.0630607592536)	;
glVertex2f	(0.612541098828,-3.0630607592536)	;
glVertex2f	(0.7036120309605,-3.0594179219683)	;
glVertex2f	(0.7691831020959,-3.0575965033257)	;
glVertex2f	(0.8511469410151,-3.055775084683)	;
glVertex2f	(0.9440392917902,-3.055775084683)	;
glVertex2f	 (1.0369316425654,-3.0521322473977)	;
glVertex2f	 (1.1498595984096,-3.0466679914698)	;
glVertex2f	(1.2354662746142,-3.0412037355418)	;
glVertex2f	 (1.3647869982423,-3.0339180609712)	;
glVertex2f	(1.4631436049454,-3.0339180609712)	;
glVertex2f	(1.6070356777147,-3.0302752236859)	;
glVertex2f	(1.7217850522016,-3.0375608982565)	;
glVertex2f	(1.7982846351929,-3.0357394796139)	;
glVertex2f	 (1.8465358386979,-3.0357967787803)	;
glVertex2f	 (1.8431380062413,-2.8877495973127)	;
glVertex2f	(1.8411994077782,-2.7738116529705)	;
glVertex2f	 (-0.9723512298722,-2.7556809359781)	;
glVertex2f	(-7.8178533361503,-2.7371192466688)	;
glVertex2f	 (-8.0040509988545,-2.9217723503272)	;
glVertex2f	(-7.6865820127341,-2.9217723503272)	;
glVertex2f	(-6.236227124088,-2.9152490149959)	;
glVertex2f	(-5.6360802736138,-2.9195979052167)	;
glVertex2f	 (-5.794814766674,-3.1218213004852)	;
glVertex2f	(-5.6773947307116,-3.1392168613686)	;
glVertex2f	 (-5.6121613773992,-3.152263532031)	;
glVertex2f	 (-5.5099624572097,-3.1696590929143)	;
glVertex2f	(-5.4729968903327,-3.2087991049018)	;
glVertex2f	(-5.453426884339,-3.2501135619997)	;
glVertex2f	 (-5.4642991098911,-3.2914280190975)	;
glVertex2f	 (-5.4925668963264,-3.3262191408641)	;
glVertex2f	(-5.5730213654118,-3.3436147017475)	;
glVertex2f	(-5.6491269442762,-3.3588358175204)	;
glVertex2f	(-5.7208836329199,-3.3653591528516)	;
glVertex2f	(-5.8187336628885,-3.3718824881828)	;
glVertex2f	(-5.8752692357593,-3.3762313784037)	;
glVertex2f	(-5.9274559184092,-3.3762313784037)	;
glVertex2f	(-5.9731192657279,-3.3631847077412)	;
glVertex2f	(-6,-3.4)	;
glVertex2f	(-6.0383526190403,-3.4653836279306)	;
glVertex2f	 (-6.1601215452235,-3.6001992247763)	;
glVertex2f	 (-6.6,-3.6)	;
glVertex2f	(-8.6740768441519,-3.5622128371493)	;
glVertex2f	(-8.8927242594483,-3.6871542173187)	;
glVertex2f	(-8.9747170401845,-3.7379116530125)	;
glVertex2f	(-9.0059523852269,-3.8433309425305)	;
glEnd();
glPopMatrix();
}

void kotakplay () {
glPushMatrix();
glColor3ub(255,0,0);
glBegin(GL_QUADS);
glVertex2f(-200,100);
glVertex2f(200,100);
glVertex2f(200,-100);
glVertex2f(-200,-100);
glEnd();

glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(-150,70);
glVertex2f(-150,-70);
glVertex2f(150,0);
glEnd();
glPopMatrix();
}

void gawangkiri() {
glPushMatrix();
glTranslated(65,10,0);
glScaled(20,15,1);
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f	(-36.3018002566621, -17.0297305117635)	;
glVertex2f	(-35.7469092348132, -17.0018212039202)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-36.2867072246962, 0.2719120812675)	;

glEnd();
glBegin(GL_POLYGON);
glVertex2f	(-33.7453032470273, -11.0345266952294)	;
glVertex2f	(-33.1904122251784, -11.0066173873861)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glBegin(GL_POLYGON);
glVertex2f	(-36.2867072246962, 0.2719120812675)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(65,10,0);
glScaled(20,15,1);
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f	(-36.3018002566621, -17.0297305117635)	;
glVertex2f	(-35.7469092348132, -17.0018212039202)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-36.2867072246962, 0.2719120812675)	;

glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f	(-33.7453032470273, -11.0345266952294)	;
glVertex2f	(-33.1904122251784, -11.0066173873861)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f	(-36.2867072246962, 0.2719120812675)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glPopMatrix();
}

void gawangkanan() {
glPushMatrix();
glScaled(-1,1,1);
glTranslated(65,10,0);
glScaled(20,15,1);
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f	(-36.3018002566621, -17.0297305117635)	;
glVertex2f	(-35.7469092348132, -17.0018212039202)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-36.2867072246962, 0.2719120812675)	;

glEnd();
glBegin(GL_POLYGON);
glVertex2f	(-33.7453032470273, -11.0345266952294)	;
glVertex2f	(-33.1904122251784, -11.0066173873861)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glBegin(GL_POLYGON);
glVertex2f	(-36.2867072246962, 0.2719120812675)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glPopMatrix();
glPushMatrix();
glScaled(-1,1,1);
glTranslated(65,10,0);
glScaled(20,15,1);
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f	(-36.3018002566621, -17.0297305117635)	;
glVertex2f	(-35.7469092348132, -17.0018212039202)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-36.2867072246962, 0.2719120812675)	;

glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f	(-33.7453032470273, -11.0345266952294)	;
glVertex2f	(-33.1904122251784, -11.0066173873861)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f	(-36.2867072246962, 0.2719120812675)	;
glVertex2f	(-35.6955959809095, 0.2599321049931)	;
glVertex2f	(-33.1390989712747, 4.2647282884591)	;
glVertex2f	(-33.7302102150614, 4.2767082647334)	;

glEnd();
glPopMatrix();
}

void langit () {
glPushMatrix();
glTranslated(0,90,0);
glColor3ub(132,0,0);
glBegin(GL_POLYGON);
glVertex2f(-700,300);
glVertex2f(700,300);
glColor3ub(245,86,18);
glVertex2f(700,-100);
glVertex2f(-700,-100);
glEnd();
glPopMatrix();
}

void background () {
       glPushMatrix();
    glScaled(100,100,0);
    langit();
    matahari();
    glPushMatrix();
    glScaled(-1,1,1);
    gunung();
    glPopMatrix();
    gunung();
    glPushMatrix();
    glScaled(-1,1,1);
    rumput();
    glPopMatrix();
    rumput();
    aspal();
    glPushMatrix();
    glScaled(-1,1,1);
    garisLapangan();
    glPopMatrix();
    garisLapangan();
    glPopMatrix();
    marka();
    glPushMatrix();
    glScaled(-1,1,1);
    marka();
    glPopMatrix();
    gawangkiri();
gawangkanan();

}

void pilihan() {
    glPushMatrix();
    glScaled(20,20,1);
    glPushMatrix();
    glColor3ub(241,92,10);
    glBegin(GL_POLYGON);
glVertex2f	(-5.9988966983163,2.0368384953646)	;
glVertex2f	(-5.3922398238614,-1.3913977823034)	;
glVertex2f	(6,-2)	;
glVertex2f	(5.3916796252086,1.4532742448434)	;
glEnd();
glPopMatrix();

glPushMatrix();
 glColor3ub(14,107,155);
    glBegin(GL_POLYGON);
glVertex2f	(-5.3998811927337,1.4623993222124)	;
glVertex2f	(-5.3922398238614,-1.3913977823034)	;
glVertex2f	(5.4,-1.4)	;
glVertex2f	(5.3916796252086,1.4532742448434)	;
glEnd();
glPopMatrix();
glPopMatrix();
}

void panah () {
glPushMatrix();
glScaled(20,20,1);
glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f	(-10.2859393166742,-1.1008563842969)	;
glVertex2f	(-9.5,0)	;
glVertex2f	(-10.2859393166742,1.1008563842969)	;
glVertex2f	(-7.2,0)	;

glEnd();
glPopMatrix();
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f	(-10.2859393166742,-1.1008563842969)	;
glVertex2f	(-9.5,0)	;
glVertex2f	(-10.2859393166742,1.1008563842969)	;
glVertex2f	(-7.2,0)	;

glEnd();
glPushMatrix();
glPopMatrix();
glColor3ub(0,0,0);
glPushMatrix();
glBegin(GL_LINES);
glVertex2f	(-9.5,0)	;
glVertex2f	(-7.2,0)	;

glEnd();
glPopMatrix();
glPopMatrix();


}

void bgmenu () {
glPushMatrix();
glScaled(20,20,1);
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(-15,5);
glVertex2f(15,5);
glVertex2f(15,-20);
glVertex2f(-15,-20);
glEnd();
glPopMatrix();

}

void menu () {
background();
glPushMatrix();
glTranslated(0,100,0);

bgmenu();
pilihan();
displayText(-30,-5,255,255,255,"PLAY");
glPushMatrix();
glTranslatef(0,-150.0f,0);
pilihan();
displayText(-40,-5,255,255,255,"ABOUT");
glPopMatrix();
glPushMatrix();
glTranslatef(0,-300.0f,0);
pilihan();
displayText(-30,-5,255,255,255,"EXIT");
glPopMatrix();
glPushMatrix();
glColor3ub(255,255,255);
glTranslatef(panahpilih[4],panahpilih[5],0);
panah();
glPopMatrix();
glPopMatrix();
displayText(-80,300,255,255,255,"HEAD SOCCER");
Keterangan(-280,-270,255,255,255,"Tekan Arah Untuk Berpindah");
Keterangan(-280,-290,255,255,255,"Tekan Enter Untuk Memilih");

}

void about () {
glPushMatrix();
background();
glPushMatrix();
glTranslated(0,100,0);
bgmenu();
displayText(-250,0,255,255,255,"HEAD SOCCER V1.0 2018");
displayText(-250,-50,255,255,255,"Developed By : Geofany Galindra");
displayText(-95,-100,255,255,255,"M. Ifantara Putra");
Keterangan(-280,-390,255,255,255,"Tekan ESC Untuk Kembali Ke Menu Awal");
glPopMatrix();
glPopMatrix();
}

void menulvl () {
background();
glPushMatrix();
glTranslated(0,100,0);

bgmenu();
pilihan();
displayText(-30,-5,255,255,255,"EASY");
glPushMatrix();
glTranslatef(0,-150.0f,0);
pilihan();
displayText(-40,-5,255,255,255,"MEDIUM");
glPopMatrix();
glPushMatrix();
glTranslatef(0,-300.0f,0);
pilihan();
displayText(-30,-5,255,255,255,"HARD");
glPopMatrix();
glPushMatrix();
glColor3ub(255,255,255);
glTranslatef(panahpilih[4],panahpilih[5],0);
panah();
glPopMatrix();
Keterangan(-280,-350,255,255,255,"Tekan Arah Untuk Berpindah");
Keterangan(-280,-370,255,255,255,"Tekan Enter Untuk Memilih");
Keterangan(-280,-390,255,255,255,"Tekan ESC Untuk Kembali Ke Menu Awal");
glPopMatrix();
}

void Lose () {
    glPushMatrix();

background();
glPushMatrix();
 glTranslatef(0,100,0);
bgmenu();
char skorp1[100]={"0"};
sprintf(skorp1,"%i",scorep1); //konversi time ke label
char skorp2[100]={"0"};
sprintf(skorp2,"%i",scorep2); //konversi time ke label
displayText(-60,0,255,255,255,"YOU LOSE !!!");
displayText(-50,-100,255,255,255, skorp1);
glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_LINES);
glVertex2f(-25,-93);
glVertex2f(30,-93);
glEnd();
glPopMatrix();
displayText(50,-100,255,255,255, skorp2);
Keterangan(-280,-390,255,255,255,"Tekan ENTER Untuk Kembali Ke Menu Awal");
glPopMatrix();

glPopMatrix();

}

void Win () {
    glPushMatrix();

background();
glPushMatrix();
 glTranslatef(0,100,0);
bgmenu();
char skorp1[100]={"0"};
sprintf(skorp1,"%i",scorep1); //konversi time ke label
char skorp2[100]={"0"};
sprintf(skorp2,"%i",scorep2); //konversi time ke label
displayText(-60,0,255,255,255,"YOU WIN !!!");
displayText(-50,-100,255,255,255, skorp1);
glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_LINES);
glVertex2f(-25,-93);
glVertex2f(30,-93);
glEnd();
glPopMatrix();
displayText(50,-100,255,255,255, skorp2);
Keterangan(-280,-390,255,255,255,"Tekan ENTER Untuk Kembali Ke Menu Awal");
glPopMatrix();

glPopMatrix();

}

void score1 () {

char skorp1[100]={"0"};
sprintf(skorp1,"%i",scorep1); //konversi time ke label
displayText(-500,300,0,0,0,"SCORE :");
displayText(-400,300,0,0,0,skorp1);

}

void score2 () {

char skorp2[100]={"0"};

sprintf(skorp2,"%i",scorep2); //konversi time ke label
displayText(400,300,0,0,0,"SCORE :");
displayText(500,300,0,0,0,skorp2);

}

void loading () {
background();
glPushMatrix();
glTranslatef(0,100.0,0);
bgmenu();

glPushMatrix();
glTranslated(-300,-350,0);
glScaled(60,10,1);
glColor3ub(255,255,255);
glBegin(GL_QUADS);
glVertex2f(0,-2);
glVertex2f(0,2);
glVertex2f(loadingtime,2);
glVertex2f(loadingtime,-2);
glEnd();
glPopMatrix();
glPopMatrix();
glPushMatrix();
glTranslated(-239,58,0);
glScaled(10,10,1);
glColor3ub(255,255,255);
glBegin(GL_LINE_LOOP);
glVertex2f(-2,2);
glVertex2f(2,2);
glVertex2f(2,-2);
glVertex2f(-2,-2);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(-239,8,0);
glScaled(10,10,1);
glColor3ub(255,255,255);
glBegin(GL_LINE_LOOP);
glVertex2f(-2,2);
glVertex2f(2,2);
glVertex2f(2,-2);
glVertex2f(-2,-2);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(-239,-42,0);
glScaled(10,10,1);
glColor3ub(255,255,255);
glBegin(GL_LINE_LOOP);
glVertex2f(-2,2);
glVertex2f(8.5,2);
glVertex2f(8.5,-2);
glVertex2f(-2,-2);
glEnd();
glPopMatrix();
displayText(-30,150,255,255,255,"HINT");
displayText(-250,50,255,255,255,"W");
displayText(-200,50,255,255,255,"MOVE UP");
displayText(-245,0,255,255,255,"S");
displayText(-200,0,255,255,255,"MOVE DOWN");
displayText(-245,-50,255,255,255,"ENTER");
displayText(-140,-50,255,255,255,"CONFIRM GOAL");
displayText(-50,-200,255,255,255,"LOADING");

}


void kepala () {
    glPushMatrix();
    glColor3ub(237,216,166);
glScaled(20,20,1);
lingkaran(3,99,0,0);
glPopMatrix();
}

void mata () {
    glPushMatrix();
    glTranslated(-20,0,0);
glScaled(20,20,1);
glPushMatrix();
glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f	(-1.3692061685,-0.5469180218)	;
glVertex2f	(1.1921780376,0.6829003017)	;
glVertex2f	(1.1169733199,0.8554287716)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f	(-1.3692061685,-0.5469180218)	;
glVertex2f	(1.1921780376,0.6829003017)	;
glVertex2f	(1.1169733199,0.8554287716)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f	(1.170059003,0.4395909212)	;
glVertex2f	(1.1523637753,-0.7902274023)	;
glVertex2f	(-1.3603585547,-0.7990750161)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f	(1.170059003,0.4395909212)	;
glVertex2f	(1.1523637753,-0.7902274023)	;
glVertex2f	(-1.3603585547,-0.7990750161)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(255,0,0);
glBegin(GL_POLYGON);
glVertex2f	(-0.1172688105,-0.1930134682)	;
glVertex2f	(-0.1305402312,-0.2814896066)	;
glVertex2f	(-0.1393878451,-0.3611181312)	;
glVertex2f	(-0.1305402312,-0.4318990419)	;
glVertex2f	(-0.1216926174,-0.5071037595)	;
glVertex2f	(-0.086302162,-0.5734608633)	;
glVertex2f	(-0.0597593205,-0.6398179671)	;
glVertex2f	(-0.0243688652,-0.697327457)	;
glVertex2f	(0.0331406248,-0.7725321746)	;
glVertex2f	(0.7144068903,-0.7902274023)	;
glVertex2f	(0.7365259249,-0.7371417193)	;
glVertex2f	(0.7542211526,-0.6619370017)	;
glVertex2f	(0.7674925733,-0.5778846702)	;
glVertex2f	(0.7763401872,-0.5026799526)	;
glVertex2f	(0.7630687664,-0.4318990419)	;
glVertex2f	(0.7542211526,-0.3389990966)	;
glVertex2f	(0.7365259249,-0.2505229582)	;
glVertex2f	(0.7099830834,-0.1576230129)	;
glVertex2f	(0.679016435,-0.0691468745)	;
glVertex2f	(0.6392021727,0.0016340362)	;
glVertex2f	(0.5861164897,0.0635673331)	;
glVertex2f	(0.5153355789,0.0989577884)	;
glEnd();
glPopMatrix();
glPopMatrix();
glPopMatrix();
}

void rambut () {
glPushMatrix();
glTranslated(2,50,0);
glScaled(50,50,1);
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f	(-1.0702398278,-0.5765890233);
glVertex2f	(-0.450269934,0.0957159914);
glVertex2f	(-1.2312709691,0.0232519778);
glVertex2f	(-0.4301410414,0.2970049179);
glVertex2f	(-0.7964868877,0.5546547439);
glVertex2f	(-0.2570325646,0.37349471);
glVertex2f	(0.2421639733,0.6834796569);
glVertex2f	(0.0247719326,0.3171338106);
glVertex2f	(0.8661596456,0.5667320795);
glVertex2f	(0.4233240072,0.2366182399);
glVertex2f	(1.1358868072,0.4379071665);
glVertex2f	(0.588380927,0.1037675484);
glVertex2f	(1.2325054919,-0.2384236267);
glVertex2f	(0.4756591281,-0.081418264);
glVertex2f	(0.664870719,-0.3833516538);
glVertex2f	(0.209957745,-0.1015471567);
glVertex2f	(0.0569781609,-0.33906809);
glVertex2f	(-0.0758725307,-0.1176502708);
glVertex2f	(-0.2369036719,-0.4598414459);
glVertex2f	(-0.2892387928,-0.0975213781);
glEnd();
glPopMatrix();
}

void mulut () {
glPushMatrix();
glScaled(20,20,1);
glTranslated(-2,-1.7,0);
glBegin(GL_LINES);
glVertex2f(0,0);
glVertex2f(2,0);
glEnd();
glPopMatrix();
}

void badan () {

glPushMatrix();
glTranslated(20,-70,0);
glScaled(25,25,1);
glColor3ub(118,180,204);
glBegin(GL_POLYGON);
glVertex2f(-0.8472435751,0.5765931079);
glVertex2f(-0.8472435751,-1.3648248165);
glVertex2f(-0.678987355,-1.3648248165);
glVertex2f(-0.5560308864,-1.3648248165);
glVertex2f(-0.4330744179,-1.3583534234);
glVertex2f(-0.3295321286,-1.3324678511);
glVertex2f(-0.2195184462,-1.3130536719);
glVertex2f(-0.0900905846,-1.2742253134);
glVertex2f(0.0134517047,-1.2289255618);
glVertex2f(0.1428795664,-1.164211631);
glVertex2f(0.2528932487,-1.0800835209);
glVertex2f(0.356435538,-0.9765412316);
glVertex2f(0.4405636481,-0.84711337);
glVertex2f(0.5052775789,-0.7823994392);
glVertex2f(0.5,1);

glEnd();
glPopMatrix();
}

void body () {
    glPushMatrix();
    glPushMatrix();
    glScaled(-1,1,1);
    badan();
    glPopMatrix();
badan();
glPopMatrix();
}

void sepatug () {
    glPushMatrix();
    glTranslated(-15,-110,0);
    glScaled(20,20,1);
    glPushMatrix();
    glPushMatrix();
glColor3ub(191,82,16);
glBegin(GL_POLYGON);
glVertex2f(-1.522, -0.808);
glVertex2f(1.238, -0.808);
glVertex2f(1.21, 0.68);
glVertex2f(0.49, 0.68);
glVertex2f(0.47, 0.4);
glVertex2f(-1.53, -0.24);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-1.522, -0.808);
glVertex2f(1.238, -0.808);
glVertex2f(1.21, 0.68);
glVertex2f(0.49, 0.68);
glVertex2f(0.47, 0.4);
glVertex2f(-1.53, -0.24);
glEnd();
glPopMatrix();


glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(-0.9672048269, -0.0924136501);
glVertex2f(-0.8176813004, -0.4419491667);
glVertex2f(-0.7419486052, -0.406995615);
glVertex2f(-0.8992395876, -0.0691112823);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-0.5069830635, 0.0707029243);
glVertex2f(-0.3186222573, -0.3157280079);
glVertex2f(-0.2467732901, -0.2827163202);
glVertex2f(-0.4331922322, 0.1095402039);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-0.0564706199, 0.1891566271);
glVertex2f(0.1668437379, -0.201158033);
glVertex2f(0.2484020251, -0.1564951615);
glVertex2f(0.0153783474, 0.2260520427);
glEnd();
glPopMatrix();
glPopMatrix();
glPopMatrix();
}

void sepatu (){
    glPushMatrix();
glPushMatrix();
glRotated(15,0,0,1);
glTranslated(0.3,0,0);
sepatug();
glPopMatrix();

glPushMatrix();
glRotated(-15,0,0,1);
glTranslated(0.5,0.5,0);
sepatug();
glPopMatrix();
glPopMatrix();
}

void tangan () {
glPushMatrix();
glTranslated(1,-75,0);
glScaled(-1,1,1);
glScaled(11,11,1);
 glBegin(GL_POLYGON);
glVertex2f	(-0.8,0.8)	;
glVertex2f	(-0.6908801829,0.9518188759)	;
glVertex2f	(-0.5485499867,1.0277283139)	;
glVertex2f	(-0.4299414899,1.0704273728)	;
glVertex2f	(-0.3018443133,1.0799160525)	;
glVertex2f	(-0.1500254374,1.0941490721)	;
glVertex2f	(-0.0314169406,1.0894047323)	;
glVertex2f	(0.096680236,1.0751717126)	;
glVertex2f	(0.2200330727,1.0704273728)	;
glVertex2f	(0.3244085499,1.0324726538)	;
glVertex2f	(0.4287840271,0.9945179348)	;
glVertex2f	(0.5189264847,0.9423301962)	;
glVertex2f	(0.5995802626,0.8901424576)	;
glVertex2f	(0.656512341,0.8237216994)	;
glVertex2f	(0.6754897005,0.7430679215)	;
glVertex2f	(0.6470236613,0.6766471633)	;
glVertex2f	(0.6043246024,0.6054820652)	;
glVertex2f	(0.5529995099,0.5597098785)	;
glVertex2f	(0.4525057265,0.4773848886)	;
glVertex2f	(0.5529995099,0.3597098785)	;
glVertex2f	(0.6707453606,0.278122614)	;
glVertex2f	(0.7561434784,0.1974688361)	;
glVertex2f	(0.8273085765,0.126303738)	;
glVertex2f	(0.8794963151,0.0693716595)	;
glVertex2f	(0.9221953739,-0.0112821183)	;
glVertex2f	(0.9269397138,-0.1204019354)	;
glVertex2f	(0.8889849948,-0.3006868505)	;
glVertex2f	(0.8035868771,-0.4477613866)	;
glVertex2f	(0.787119521,-0.6209055937)	;
glVertex2f	(0.7751208379,-0.7798651777)	;
glVertex2f	(0.7229330993,-0.8605189556)	;
glVertex2f	(0.6660010208,-0.917451034)	;
glVertex2f	(0.6090689423,-0.9696387727)	;
glVertex2f	(0.5284151645,-0.9981048119)	;
glVertex2f	(0.4287840271,-1.0123378315)	;
glVertex2f	(0.3386415695,-1.0123378315)	;
glVertex2f	(0.2484991119,-1.0028491518)	;
glVertex2f	(0.1536123145,-0.9601500929)	;
glVertex2f	(0.0729585366,-0.9032180144)	;
glVertex2f	(-0.0978376988,-1.0787585897)	;
glVertex2f	(-0.1784914766,-1.1309463283)	;
glVertex2f	(-0.2828669538,-1.1309463283)	;
glVertex2f	(-0.3967311108,-1.0977359492)	;
glVertex2f	(-0.4821292285,-1.0265708511)	;
glVertex2f	(-0.5343169671,-0.9459170733)	;
glVertex2f	(-0.6102264051,-0.8367972562)	;
glVertex2f	(-0.7573009411,-0.8700076353)	;
glVertex2f	(-0.8569320785,-0.808331217)	;
glVertex2f	(-0.9186084968,-0.6897227201)	;
glVertex2f	(-0.9518188759,-0.5141821448)	;
glVertex2f	(-0.9613075557,-0.3101755303)	;
glVertex2f	(-0.9470745361,-0.0919358961)	;
glVertex2f	(-0.8853981177,0.1168150583)	;
glVertex2f	(-0.8047443399,0.3208216728)	;
glVertex2f	(-0.6470004901,0.5597098785)	;
glVertex2f	(-0.7430679215,0.6956245228)	;
glEnd();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f	(-0.8,0.8)	;
glVertex2f	(-0.6908801829,0.9518188759)	;
glVertex2f	(-0.5485499867,1.0277283139)	;
glVertex2f	(-0.4299414899,1.0704273728)	;
glVertex2f	(-0.3018443133,1.0799160525)	;
glVertex2f	(-0.1500254374,1.0941490721)	;
glVertex2f	(-0.0314169406,1.0894047323)	;
glVertex2f	(0.096680236,1.0751717126)	;
glVertex2f	(0.2200330727,1.0704273728)	;
glVertex2f	(0.3244085499,1.0324726538)	;
glVertex2f	(0.4287840271,0.9945179348)	;
glVertex2f	(0.5189264847,0.9423301962)	;
glVertex2f	(0.5995802626,0.8901424576)	;
glVertex2f	(0.656512341,0.8237216994)	;
glVertex2f	(0.6754897005,0.7430679215)	;
glVertex2f	(0.6470236613,0.6766471633)	;
glVertex2f	(0.6043246024,0.6054820652)	;
glVertex2f	(0.5529995099,0.5597098785)	;
glVertex2f	(0.4525057265,0.4773848886)	;
glVertex2f	(0.5529995099,0.3597098785)	;
glVertex2f	(0.6707453606,0.278122614)	;
glVertex2f	(0.7561434784,0.1974688361)	;
glVertex2f	(0.8273085765,0.126303738)	;
glVertex2f	(0.8794963151,0.0693716595)	;
glVertex2f	(0.9221953739,-0.0112821183)	;
glVertex2f	(0.9269397138,-0.1204019354)	;
glVertex2f	(0.8889849948,-0.3006868505)	;
glVertex2f	(0.8035868771,-0.4477613866)	;
glVertex2f	(0.787119521,-0.6209055937)	;
glVertex2f	(0.7751208379,-0.7798651777)	;
glVertex2f	(0.7229330993,-0.8605189556)	;
glVertex2f	(0.6660010208,-0.917451034)	;
glVertex2f	(0.6090689423,-0.9696387727)	;
glVertex2f	(0.5284151645,-0.9981048119)	;
glVertex2f	(0.4287840271,-1.0123378315)	;
glVertex2f	(0.3386415695,-1.0123378315)	;
glVertex2f	(0.2484991119,-1.0028491518)	;
glVertex2f	(0.1536123145,-0.9601500929)	;
glVertex2f	(0.0729585366,-0.9032180144)	;
glVertex2f	(-0.0978376988,-1.0787585897)	;
glVertex2f	(-0.1784914766,-1.1309463283)	;
glVertex2f	(-0.2828669538,-1.1309463283)	;
glVertex2f	(-0.3967311108,-1.0977359492)	;
glVertex2f	(-0.4821292285,-1.0265708511)	;
glVertex2f	(-0.5343169671,-0.9459170733)	;
glVertex2f	(-0.6102264051,-0.8367972562)	;
glVertex2f	(-0.7573009411,-0.8700076353)	;
glVertex2f	(-0.8569320785,-0.808331217)	;
glVertex2f	(-0.9186084968,-0.6897227201)	;
glVertex2f	(-0.9518188759,-0.5141821448)	;
glVertex2f	(-0.9613075557,-0.3101755303)	;
glVertex2f	(-0.9470745361,-0.0919358961)	;
glVertex2f	(-0.8853981177,0.1168150583)	;
glVertex2f	(-0.8047443399,0.3208216728)	;
glVertex2f	(-0.6470004901,0.5597098785)	;
glVertex2f	(-0.7430679215,0.6956245228)	;
glEnd();
glPopMatrix();
glPopMatrix();
}





void kepala2 () {
    glPushMatrix();
    glColor3ub(237,216,166);
glScaled(20,20,1);
lingkaran(3,99,0,0);
glPopMatrix();
}

void badan2 () {

glPushMatrix();
glTranslated(20,-70,0);
glScaled(25,25,1);
glColor3ub(255,0,0);
glBegin(GL_POLYGON);
glVertex2f(-0.8472435751,0.5765931079);
glVertex2f(-0.8472435751,-1.3648248165);
glVertex2f(-0.678987355,-1.3648248165);
glVertex2f(-0.5560308864,-1.3648248165);
glVertex2f(-0.4330744179,-1.3583534234);
glVertex2f(-0.3295321286,-1.3324678511);
glVertex2f(-0.2195184462,-1.3130536719);
glVertex2f(-0.0900905846,-1.2742253134);
glVertex2f(0.0134517047,-1.2289255618);
glVertex2f(0.1428795664,-1.164211631);
glVertex2f(0.2528932487,-1.0800835209);
glVertex2f(0.356435538,-0.9765412316);
glVertex2f(0.4405636481,-0.84711337);
glVertex2f(0.5052775789,-0.7823994392);
glVertex2f(0.5,1);

glEnd();
glPopMatrix();
}

void mulut2 () {
glPushMatrix();
glColor3ub(0,0,0);
glTranslated(-1.2,-1.7,0);
glBegin(GL_LINES);
glVertex2f(0,0);
glVertex2f(2,0);
glEnd();
glPopMatrix();
}

void mata2 () {
    glTranslated(-20,0,0);
glScaled(20,20,1);
glPushMatrix();
glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f	(-1.3692061685,-0.5469180218)	;
glVertex2f	(1.1921780376,0.6829003017)	;
glVertex2f	(1.1169733199,0.8554287716)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f	(-1.3692061685,-0.5469180218)	;
glVertex2f	(1.1921780376,0.6829003017)	;
glVertex2f	(1.1169733199,0.8554287716)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f	(1.170059003,0.4395909212)	;
glVertex2f	(1.1523637753,-0.7902274023)	;
glVertex2f	(-1.3603585547,-0.7990750161)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f	(1.170059003,0.4395909212)	;
glVertex2f	(1.1523637753,-0.7902274023)	;
glVertex2f	(-1.3603585547,-0.7990750161)	;
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,255);
glBegin(GL_POLYGON);
glVertex2f	(-0.1172688105,-0.1930134682)	;
glVertex2f	(-0.1305402312,-0.2814896066)	;
glVertex2f	(-0.1393878451,-0.3611181312)	;
glVertex2f	(-0.1305402312,-0.4318990419)	;
glVertex2f	(-0.1216926174,-0.5071037595)	;
glVertex2f	(-0.086302162,-0.5734608633)	;
glVertex2f	(-0.0597593205,-0.6398179671)	;
glVertex2f	(-0.0243688652,-0.697327457)	;
glVertex2f	(0.0331406248,-0.7725321746)	;
glVertex2f	(0.7144068903,-0.7902274023)	;
glVertex2f	(0.7365259249,-0.7371417193)	;
glVertex2f	(0.7542211526,-0.6619370017)	;
glVertex2f	(0.7674925733,-0.5778846702)	;
glVertex2f	(0.7763401872,-0.5026799526)	;
glVertex2f	(0.7630687664,-0.4318990419)	;
glVertex2f	(0.7542211526,-0.3389990966)	;
glVertex2f	(0.7365259249,-0.2505229582)	;
glVertex2f	(0.7099830834,-0.1576230129)	;
glVertex2f	(0.679016435,-0.0691468745)	;
glVertex2f	(0.6392021727,0.0016340362)	;
glVertex2f	(0.5861164897,0.0635673331)	;
glVertex2f	(0.5153355789,0.0989577884)	;
glEnd();
glPopMatrix();
glPopMatrix();
}

void body2 () {
    glPushMatrix();
    glPushMatrix();
    glScaled(-1,1,1);
    badan2();
    glPopMatrix();
badan2();
glPopMatrix();
}

void sepatug2 () {
    glPushMatrix();
    glTranslated(0,-5.6,0);
    glScaled(1,1,1);
    glPushMatrix();
    glPushMatrix();
glColor3ub(191,82,16);
glBegin(GL_POLYGON);
glVertex2f(-1.522, -0.808);
glVertex2f(1.238, -0.808);
glVertex2f(1.21, 0.68);
glVertex2f(0.49, 0.68);
glVertex2f(0.47, 0.4);
glVertex2f(-1.53, -0.24);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-1.522, -0.808);
glVertex2f(1.238, -0.808);
glVertex2f(1.21, 0.68);
glVertex2f(0.49, 0.68);
glVertex2f(0.47, 0.4);
glVertex2f(-1.53, -0.24);
glEnd();
glPopMatrix();


glPushMatrix();
glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(-0.9672048269, -0.0924136501);
glVertex2f(-0.8176813004, -0.4419491667);
glVertex2f(-0.7419486052, -0.406995615);
glVertex2f(-0.8992395876, -0.0691112823);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-0.5069830635, 0.0707029243);
glVertex2f(-0.3186222573, -0.3157280079);
glVertex2f(-0.2467732901, -0.2827163202);
glVertex2f(-0.4331922322, 0.1095402039);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-0.0564706199, 0.1891566271);
glVertex2f(0.1668437379, -0.201158033);
glVertex2f(0.2484020251, -0.1564951615);
glVertex2f(0.0153783474, 0.2260520427);
glEnd();
glPopMatrix();
glPopMatrix();
glPopMatrix();
}

void sepatu2 (){
    glPushMatrix();
glPushMatrix();
glRotated(15,0,0,1);
glTranslated(0.3,0,0);
sepatug2();
glPopMatrix();

glPushMatrix();
glRotated(-15,0,0,1);
glTranslated(0.5,0.5,0);
sepatug2();
glPopMatrix();
glPopMatrix();
}

void tangan2 () {
glPushMatrix();
glTranslated(1,-3.8,0);
glScaled(-1,1,1);
glScaled(0.6,0.6,1);
 glBegin(GL_POLYGON);
glVertex2f	(-0.8,0.8)	;
glVertex2f	(-0.6908801829,0.9518188759)	;
glVertex2f	(-0.5485499867,1.0277283139)	;
glVertex2f	(-0.4299414899,1.0704273728)	;
glVertex2f	(-0.3018443133,1.0799160525)	;
glVertex2f	(-0.1500254374,1.0941490721)	;
glVertex2f	(-0.0314169406,1.0894047323)	;
glVertex2f	(0.096680236,1.0751717126)	;
glVertex2f	(0.2200330727,1.0704273728)	;
glVertex2f	(0.3244085499,1.0324726538)	;
glVertex2f	(0.4287840271,0.9945179348)	;
glVertex2f	(0.5189264847,0.9423301962)	;
glVertex2f	(0.5995802626,0.8901424576)	;
glVertex2f	(0.656512341,0.8237216994)	;
glVertex2f	(0.6754897005,0.7430679215)	;
glVertex2f	(0.6470236613,0.6766471633)	;
glVertex2f	(0.6043246024,0.6054820652)	;
glVertex2f	(0.5529995099,0.5597098785)	;
glVertex2f	(0.4525057265,0.4773848886)	;
glVertex2f	(0.5529995099,0.3597098785)	;
glVertex2f	(0.6707453606,0.278122614)	;
glVertex2f	(0.7561434784,0.1974688361)	;
glVertex2f	(0.8273085765,0.126303738)	;
glVertex2f	(0.8794963151,0.0693716595)	;
glVertex2f	(0.9221953739,-0.0112821183)	;
glVertex2f	(0.9269397138,-0.1204019354)	;
glVertex2f	(0.8889849948,-0.3006868505)	;
glVertex2f	(0.8035868771,-0.4477613866)	;
glVertex2f	(0.787119521,-0.6209055937)	;
glVertex2f	(0.7751208379,-0.7798651777)	;
glVertex2f	(0.7229330993,-0.8605189556)	;
glVertex2f	(0.6660010208,-0.917451034)	;
glVertex2f	(0.6090689423,-0.9696387727)	;
glVertex2f	(0.5284151645,-0.9981048119)	;
glVertex2f	(0.4287840271,-1.0123378315)	;
glVertex2f	(0.3386415695,-1.0123378315)	;
glVertex2f	(0.2484991119,-1.0028491518)	;
glVertex2f	(0.1536123145,-0.9601500929)	;
glVertex2f	(0.0729585366,-0.9032180144)	;
glVertex2f	(-0.0978376988,-1.0787585897)	;
glVertex2f	(-0.1784914766,-1.1309463283)	;
glVertex2f	(-0.2828669538,-1.1309463283)	;
glVertex2f	(-0.3967311108,-1.0977359492)	;
glVertex2f	(-0.4821292285,-1.0265708511)	;
glVertex2f	(-0.5343169671,-0.9459170733)	;
glVertex2f	(-0.6102264051,-0.8367972562)	;
glVertex2f	(-0.7573009411,-0.8700076353)	;
glVertex2f	(-0.8569320785,-0.808331217)	;
glVertex2f	(-0.9186084968,-0.6897227201)	;
glVertex2f	(-0.9518188759,-0.5141821448)	;
glVertex2f	(-0.9613075557,-0.3101755303)	;
glVertex2f	(-0.9470745361,-0.0919358961)	;
glVertex2f	(-0.8853981177,0.1168150583)	;
glVertex2f	(-0.8047443399,0.3208216728)	;
glVertex2f	(-0.6470004901,0.5597098785)	;
glVertex2f	(-0.7430679215,0.6956245228)	;
glEnd();

glPushMatrix();
glColor3ub(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f	(-0.8,0.8)	;
glVertex2f	(-0.6908801829,0.9518188759)	;
glVertex2f	(-0.5485499867,1.0277283139)	;
glVertex2f	(-0.4299414899,1.0704273728)	;
glVertex2f	(-0.3018443133,1.0799160525)	;
glVertex2f	(-0.1500254374,1.0941490721)	;
glVertex2f	(-0.0314169406,1.0894047323)	;
glVertex2f	(0.096680236,1.0751717126)	;
glVertex2f	(0.2200330727,1.0704273728)	;
glVertex2f	(0.3244085499,1.0324726538)	;
glVertex2f	(0.4287840271,0.9945179348)	;
glVertex2f	(0.5189264847,0.9423301962)	;
glVertex2f	(0.5995802626,0.8901424576)	;
glVertex2f	(0.656512341,0.8237216994)	;
glVertex2f	(0.6754897005,0.7430679215)	;
glVertex2f	(0.6470236613,0.6766471633)	;
glVertex2f	(0.6043246024,0.6054820652)	;
glVertex2f	(0.5529995099,0.5597098785)	;
glVertex2f	(0.4525057265,0.4773848886)	;
glVertex2f	(0.5529995099,0.3597098785)	;
glVertex2f	(0.6707453606,0.278122614)	;
glVertex2f	(0.7561434784,0.1974688361)	;
glVertex2f	(0.8273085765,0.126303738)	;
glVertex2f	(0.8794963151,0.0693716595)	;
glVertex2f	(0.9221953739,-0.0112821183)	;
glVertex2f	(0.9269397138,-0.1204019354)	;
glVertex2f	(0.8889849948,-0.3006868505)	;
glVertex2f	(0.8035868771,-0.4477613866)	;
glVertex2f	(0.787119521,-0.6209055937)	;
glVertex2f	(0.7751208379,-0.7798651777)	;
glVertex2f	(0.7229330993,-0.8605189556)	;
glVertex2f	(0.6660010208,-0.917451034)	;
glVertex2f	(0.6090689423,-0.9696387727)	;
glVertex2f	(0.5284151645,-0.9981048119)	;
glVertex2f	(0.4287840271,-1.0123378315)	;
glVertex2f	(0.3386415695,-1.0123378315)	;
glVertex2f	(0.2484991119,-1.0028491518)	;
glVertex2f	(0.1536123145,-0.9601500929)	;
glVertex2f	(0.0729585366,-0.9032180144)	;
glVertex2f	(-0.0978376988,-1.0787585897)	;
glVertex2f	(-0.1784914766,-1.1309463283)	;
glVertex2f	(-0.2828669538,-1.1309463283)	;
glVertex2f	(-0.3967311108,-1.0977359492)	;
glVertex2f	(-0.4821292285,-1.0265708511)	;
glVertex2f	(-0.5343169671,-0.9459170733)	;
glVertex2f	(-0.6102264051,-0.8367972562)	;
glVertex2f	(-0.7573009411,-0.8700076353)	;
glVertex2f	(-0.8569320785,-0.808331217)	;
glVertex2f	(-0.9186084968,-0.6897227201)	;
glVertex2f	(-0.9518188759,-0.5141821448)	;
glVertex2f	(-0.9613075557,-0.3101755303)	;
glVertex2f	(-0.9470745361,-0.0919358961)	;
glVertex2f	(-0.8853981177,0.1168150583)	;
glVertex2f	(-0.8047443399,0.3208216728)	;
glVertex2f	(-0.6470004901,0.5597098785)	;
glVertex2f	(-0.7430679215,0.6956245228)	;
glEnd();
glPopMatrix();
glPopMatrix();
}

void rambut2 () {
    glPushMatrix();
    glTranslated(6,-4.5,0);
glBegin(GL_POLYGON);
glVertex2f	(-6.7043247685187,6.4677638029625)	;
glVertex2f	(-6.8495590868689,6.6233720011948)	;
glVertex2f	 (-6.9740456454547,6.8308495988378)	;
glVertex2f	(-8,8)	;
glVertex2f	 (-7.7520866366161,7.8889853468173)	;
glVertex2f	 (-6.8495590868689,7.1316921154202)	;
glVertex2f	(-6.5590904501686,7.0072055568344)	;
glVertex2f	(-6.4653381304917,7.0354389077599)	;
glVertex2f	 (-6.4087852801344,7.1285847789366)	;
glVertex2f	 (-6.4108979724123,7.3245257201792)	;
glVertex2f	(-6.7018269027999,8.1624010396955)	;
glVertex2f	 (-6.8763842610325,8.7015893240139)	;
glVertex2f	(-6.8493139224494,8.7072764253034)	;
glVertex2f	(-6.2464821447489,7.6919807997026)	;
glVertex2f	(-6.0494346384646,7.4698848816024)	;
glVertex2f	 (-5.9592603559277,7.4114385873655)	;
glVertex2f	(-5.9241925793855,7.3913998579129)	;
glVertex2f	 (-5.7789117908538,7.3847202814286)	;
glVertex2f	 (-5.66201920238,7.4615354109971)	;
glVertex2f	(-5.6219417434747,7.5750882112288)	;
glVertex2f	(-5.5735148139642,7.7437475174553)	;
glVertex2f	(-5.5334373550589,8.5269278602296)	;
glVertex2f	 (-5.4888618603238,8.9486423354157)	;
glVertex2f	(-5.4461801567662,8.8888879504351)	;
glVertex2f	(-5.2498443204013,7.8645270650528)	;
glVertex2f	(-5.1346037207958,7.5828278215727)	;
glVertex2f	(-4.9681450769211,7.3950283259193)	;
glVertex2f	(-4.8614408180272,7.382223814852)	;
glVertex2f	(-4.7120548555756,7.4974644144575)	;
glVertex2f	(-3.7943982290873,8.8888879504351)	;
glVertex2f	(-3.5157512294835,9.2577104043221)	;
glVertex2f	 (-3.4512044708117,9.2518336667242)	;
glVertex2f	(-3.9458300684593,8.2223354216025)	;
glVertex2f	(-4.0374209323153,7.6767724499387)	;
glVertex2f	(-4.0533497782033,7.4258931272028)	;
glVertex2f	(-3.9657411258193,7.2666046683228)	;
glVertex2f	 (-3.8622036275473,7.2307647650748)	;
glVertex2f	(-2.6993978777238,7.9236695612026)	;
glVertex2f	 (-2.21356807814,8.1705666724665)	;
glVertex2f	 (-2.2494079813879,8.0909224430265)	;
glVertex2f	 (-2.6555935515318,7.8320786973466)	;
glVertex2f	 (-3.0976190249236,7.4258931272028)	;
glVertex2f	(-3.3363544347133,7.0255458937306)	;
glVertex2f	 (-3.3602744005122,6.8341861673389)	;
glVertex2f	 (-3.3243944518138,6.6966463639949)	;
glVertex2f	(-3.0313748707765,6.5770465350001)	;
glVertex2f	(-1.9968363499716,6.7145863383441)	;
glVertex2f	(-2.0446762815695,6.6368464494975)	;
glVertex2f	 (-2.6232754331682,6.3173489480532)	;
glVertex2f	(-2.9416749990304,6.1584471335184)	;
glVertex2f	(-3.5576141183536,6.1704071164178)	;
glVertex2f	 (-3.7669138190945,6.5890065178996)	;
glVertex2f	 (-4.2333531521742,6.8999660732861)	;
glVertex2f	(-4.813412322799,7.0793658167783)	;
glVertex2f	(-5.4353314335719,7.085345808228)	;
glVertex2f	 (-5.8180508863552,6.9896659450322)	;
glVertex2f	 (-6.1947903476888,6.81026620154)	;
glEnd();
glPopMatrix();
}

void bola() {
    //glTranslated(0,-180,0);
    glScaled(0.3,0.3,1);
    glPushMatrix();
    glTranslated(-3,-5,0);
    glColor3ub(255,255,255);
    glScaled(34,34,1);
    lingkaran(3,99,0,0);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glScaled(10,10,1);
glBegin(GL_POLYGON);
glVertex2f	(-2.1583753099439,2.9453809853466)	;
glVertex2f	(1.849862789432,2.858007947758)	;
glVertex2f	(3.2696746502463,-1.4014276346851)	;
glVertex2f	(0,-4)	;
glVertex2f	(-3.5781871707583,-1.1502301516179)	;

glEnd();


glBegin(GL_POLYGON);
glVertex2f	(-10.4297338190557,-1.6891019893757)	;
glVertex2f	(-10.4,-1.2)	;
glVertex2f	(-10.2589389583638,-0.726008747141)	;
glVertex2f	(-10.0596782875567,-0.3417203105843)	;
glVertex2f	(-9.7512986779741,0.0710339360877)	;
glVertex2f	(-9.4808734818787,0.3651806406125)	;
glVertex2f	(-8.9210458829443,0.7874234906563)	;
glVertex2f	(-8.3801954907534,-0.1519482431489)	;
glVertex2f	(-7.9294868305943,-0.8398719876023)	;
glVertex2f	(-7.3933807400893,-1.5420286371132)	;
glVertex2f	(-6.8136580563908,-2.2495788403855)	;
glVertex2f	(-6.9475971105737,-3.3346575677137)	;
glVertex2f	(-7.0308178924063,-4.431581135343)	;
glVertex2f	(-7.0384350434672,-5.3684907158336)	;
glVertex2f	(-7.0155835902845,-6.092120066619)	;
glVertex2f	(-7.4954641071212,-6.0997372176799)	;
glVertex2f	(-7.8458530559225,-6.01594855601)	;
glVertex2f	(-8.1733905515412,-5.8864569879747)	;
glVertex2f	(-8.5085451982207,-5.6731767582695)	;
glVertex2f	(-8.9503399597529,-5.3304049605291)	;
glVertex2f	(-9.3235803617369,-4.9647817096059)	;
glVertex2f	(-9.5749463467466,-4.7515014799007)	;
glVertex2f	(-9.7696638171,-4.3305419928275)	;
glVertex2f	(-9.9471837890222,-3.8106620750554)	;
glVertex2f	(-10.1056837639527,-3.3605221462527)	;
glVertex2f	(-10.1944437499138,-3.0181622004028)	;
glVertex2f	(-10.2958837338693,-2.6250822625751)	;
glVertex2f	(-10.371963721836,-2.2446823227418)	;
glVertex2f	(-10.4226837138138,-1.9593823678669)	;

glEnd();


glBegin(GL_POLYGON);
glVertex2f	(-2.8714792744946,-10.2878489038162)	;
glVertex2f	(-3.1390784009278,-9.9070347623535)	;
glVertex2f	(-3.3809468421271,-9.5159283467971)	;
glVertex2f	(-3.5867923239989,-9.1093835201005)	;
glVertex2f	(-3.7102996131219,-8.8263459825268)	;
glVertex2f	(-3.7514687094963,-8.5278700338128)	;
glVertex2f	(-2.9744020154304,-8.4095088817365)	;
glVertex2f	(-2.4443498996107,-8.3117322778475)	;
glVertex2f	(-1.7959366317147,-8.1522020293969)	;
glVertex2f	(-1.1938385972399,-7.9566488216187)	;
glVertex2f	(-0.6277635220926,-7.7559494767938)	;
glVertex2f	(-0.0977114062729,-7.550103994922)	;
glVertex2f	(0.3596091860058,-7.7544277772806)	;
glVertex2f	(0.8270545564371,-7.9647781939747)	;
glVertex2f	(1.3365700102072,-8.1657797032601)	;
glVertex2f	(1.8040153806384,-8.329385582911)	;
glVertex2f	(2.4584388992422,-8.5116892773792)	;
glVertex2f	(2.9819777141252,-8.6332250736914)	;
glVertex2f	(3.3138639271314,-8.6799696107345)	;
glVertex2f	(3.2,-9)	;
glVertex2f	(3.0520945196899,-9.2923230459994)	;
glVertex2f	(2.8417441029958,-9.6008369904841)	;
glVertex2f	(2.6687893159362,-9.8298852219954)	;
glVertex2f	(2.4584388992422,-10.0355611849851)	;
glVertex2f	(2.1452505010532,-10.3394006757654)	;
glVertex2f	(1.7202653366975,-10.4263622287494)	;
glVertex2f	(1.3111435525815,-10.5018924042785)	;
glVertex2f	(0.8894334058772,-10.5522458546312)	;
glVertex2f	(0.5054883469375,-10.5963051236899)	;
glVertex2f	(0.064895656351,-10.6277760301603)	;
glVertex2f	(-0.4512272097646,-10.6403643927485)	;
glVertex2f	(-0.8792315377629,-10.6340702114544)	;
glVertex2f	(-1.3009416844672,-10.602599304984)	;
glVertex2f	(-1.62823911176,-10.5648342172194)	;
glVertex2f	(-2,-10.5)	;
glVertex2f	(-2.4338943174039,-10.4074796848671)	;

glEnd();


glBegin(GL_POLYGON);
glVertex2f	(8.0911541206056,-6.2608687189156)	;
glVertex2f	(7.7817183690258,-6.2975814352047)	;
glVertex2f	(7.4775272912015,-6.3133154564715)	;
glVertex2f	(7.1890702346441,-6.2870920876935)	;
glVertex2f	(6.9111025255978,-6.25562404516)	;
glVertex2f	(6.6383794903071,-6.1926879600929)	;
glVertex2f	(6.6698475328406,-5.7678693858901)	;
glVertex2f	(6.6960709016186,-5.1961999465308)	;
glVertex2f	(6.7065602491298,-4.6979559397497)	;
glVertex2f	(6.714405669719,-4.0996240040462)	;
glVertex2f	(6.714405669719,-3.5632854738369)	;
glVertex2f	(6.6725156777558,-3.0895587535915)	;
glVertex2f	(6.6481683827359,-2.7834784733415)	;
glVertex2f	(6.6099083477046,-2.5052236731142)	;
glVertex2f	(6.8516150850919,-2.2798122521919)	;
glVertex2f	(7.1441754934089,-1.9686765798548)	;
glVertex2f	(7.4228044537107,-1.6528970915127)	;
glVertex2f	(7.6782143339875,-1.3092547071403)	;
glVertex2f	(7.868003090504,-0.9877420824277)	;
glVertex2f	(8.0373531672808,-0.6713248337132)	;
glVertex2f	(8.1844203392185,-0.3281680991919)	;
glVertex2f	(8.2824651205103,-0.0563166601556)	;
glVertex2f	(8.3894230637377,0.3447756269473)	;
glVertex2f	(8.6835574076131,0.1665123882349)	;
glVertex2f	(8.9242127798748,-0.0340337553165)	;
glVertex2f	(9.1559549902009,-0.2836022895138)	;
glVertex2f	(9.2896524192351,-0.466322109194)	;
glVertex2f	(9.4590024960119,-0.7248038053269)	;
glVertex2f	(9.6,-1)	;
glVertex2f	(9.7263973540804,-1.2685066833996)	;
glVertex2f	(9.806615811501,-1.4868791508223)	;
glVertex2f	(9.8511816211791,-1.6161199988888)	;
glVertex2f	(9.8330946771426,-1.8741694790391)	;
glVertex2f	(9.7962760772838,-2.0950810781923)	;
glVertex2f	(9.7512755663451,-2.3814479659834)	;
glVertex2f	(9.6817293221673,-2.6882696314739)	;
glVertex2f	(9.6,-3)	;
glVertex2f	(9.5207494771326,-3.3363041505823)	;
glVertex2f	(9.4094970644984,-3.6869745718784)	;
glVertex2f	(9.2866769777841,-4.0223678855983)	;
glVertex2f	(9.1733045900478,-4.3199704034061)	;
glVertex2f	(9.0221414063993,-4.6364683191699)	;
glVertex2f	(8.8942374267213,-4.9163960454358)	;
glVertex2f	(8.760928767014,-5.1787130855049)	;
glVertex2f	(8.6362206659976,-5.385126494084)	;
glVertex2f	(8.5287136823627,-5.5786390646268)	;
glVertex2f	(8.4,-5.8)	;
glVertex2f	(8.2921983183659,-5.9570636470217)	;
glVertex2f	(8.2104930108033,-6.0731711893474)	;

glEnd();


glBegin(GL_POLYGON);
glVertex2f	(6.976285605284,6.7601458458872)	;
glVertex2f	(7.115586488266,6.4583272660928)	;
glVertex2f	(7.2548873712481,6.1410308104116)	;
glVertex2f	(7.3477546265694,5.8314732926738)	;
glVertex2f	(7.4019271921735,5.5451325887663)	;
glVertex2f	(7.4328829439473,5.1504467536506)	;
glVertex2f	(7.4406218818907,4.8254113600259)	;
glVertex2f	(7.4019271921735,4.5235927802316)	;
glVertex2f	(7.3245378127391,4.2295131383807)	;
glVertex2f	(7.2781041850784,4.0515175656814)	;
glVertex2f	(7.0768917985488,4.2295131383807)	;
glVertex2f	(6.7905510946414,4.461681276684)	;
glVertex2f	(6.4964714527904,4.6628936632136)	;
glVertex2f	(6.1946528729961,4.8641060497431)	;
glVertex2f	(5.9160511070321,5.0034069327252)	;
glVertex2f	(5.5910157134074,5.1272299398203)	;
glVertex2f	(5.3356307612737,5.2355750710285)	;
glVertex2f	(4.9564228020449,5.3516591401802)	;
glVertex2f	(4.5617369669292,5.4290485196146)	;
glVertex2f	(4.2212236974176,5.4832210852188)	;
glVertex2f	(3.880710427906,5.521915774936)	;
glVertex2f	(3.7798173935457,5.7841819854415)	;
glVertex2f	(3.6555980077009,6.0222691416442)	;
glVertex2f	(3.5210270063689,6.2758837210775)	;
glVertex2f	(3.3812801972934,6.5294983005108)	;
glVertex2f	(3.2260059649873,6.7520580334829)	;
glVertex2f	(3.0707317326812,6.9590903432243)	;
glVertex2f	(2.9516881545799,7.1091887677869)	;
glVertex2f	(2.8378203842221,7.2541113846059)	;
glVertex2f	(2.7136009983772,7.3835065781943)	;
glVertex2f	(2.5635025738147,7.543956618244)	;
glVertex2f	(2.3564702640732,7.7199340815242)	;
glVertex2f	(2.1733554196864,7.8552993903187)	;
glVertex2f	(1.758607039958,8.139565133728)	;
glVertex2f	(1.9374776886911,8.2504411163862)	;
glVertex2f	(2.1363059080049,8.3620639763518)	;
glVertex2f	(2.3037401979534,8.452757550074)	;
glVertex2f	(2.4886155597716,8.5399629094221)	;
glVertex2f	(2.708373065329,8.6097271969007)	;
glVertex2f	(2.9351069996343,8.6864679131271)	;
glVertex2f	(3.1583527195656,8.7353029143621)	;
glVertex2f	(3.378110225123,8.7562322006056)	;
glVertex2f	(3.5455445150715,8.7632086293535)	;
glVertex2f	(3.7827430924986,8.7666968437274)	;
glVertex2f	(3.9606420255689,8.7701850581013)	;
glVertex2f	(4.1978406029959,8.7736732724753)	;
glVertex2f	(4.4296311822999,8.6781108099987)	;
glVertex2f	(4.6497294329024,8.5584921955408)	;
glVertex2f	(4.8650429389266,8.4293040919263)	;
glVertex2f	(5.0755717003725,8.3001159883117)	;
glVertex2f	(5.2861004618185,8.1709278846972)	;
glVertex2f	(5.4918444786861,8.032170291926)	;
glVertex2f	(5.688019006397,7.8886279545765)	;
glVertex2f	(5.8602698112164,7.7498703618054)	;
glVertex2f	(6.0564443389274,7.6063280244559)	;
glVertex2f	(6.2765425895299,7.4292924750582)	;
glVertex2f	(6.4679323726626,7.2522569256605)	;
glVertex2f	(6.6353984329036,7.1134993328893)	;
glVertex2f	(6.7693712810965,6.9843112292748)	;
glVertex2f	(6.8650661726628,6.8934010822868)	;

glEnd();


glBegin(GL_POLYGON);
glVertex2f	(-4.3198934243451,8.9871407312832)	;
glVertex2f	(-4.0790306254384,8.9759378104038)	;
glVertex2f	(-3.8325663660921,8.9759378104038)	;
glVertex2f	(-3.5861021067457,8.953531968645)	;
glVertex2f	(-3.3732466100374,8.9087202851275)	;
glVertex2f	(-3.1939998759673,8.8471042202909)	;
glVertex2f	(-2.9979487605782,8.7630823136956)	;
glVertex2f	(-2.7962961847493,8.6734589466605)	;
glVertex2f	(-2.639455292438,8.5894370400652)	;
glVertex2f	(-2.5,8.5)	;
glVertex2f	(-2.2697589034184,8.3821830037966)	;
glVertex2f	(-2.4602085583679,8.2253421114853)	;
glVertex2f	(-2.6506582133174,8.0628997587343)	;
glVertex2f	(-2.8355064078272,7.9116603268626)	;
glVertex2f	(-3.0315575232163,7.7436165136719)	;
glVertex2f	(-3.2444130199246,7.5195580960843)	;
glVertex2f	(-3.3862534550135,7.3439801256537)	;
glVertex2f	(-3.557859635302,7.135972634395)	;
glVertex2f	(-3.7086650664646,6.9071643940103)	;
glVertex2f	(-3.8542703103458,6.6627555917812)	;
glVertex2f	(-3.9946753669454,6.4027462277077)	;
glVertex2f	(-4.0934789252934,6.1531372381972)	;
glVertex2f	(-4.1766819217969,5.9243289978125)	;
glVertex2f	(-4.2546847310189,5.674720008302)	;
glVertex2f	(-4.4756382221009,5.6442389873619)	;
glVertex2f	(-4.8,5.6)	;
glVertex2f	(-5.0865479685009,5.5191128947258)	;
glVertex2f	(-5.4324848128479,5.4602300276029)	;
glVertex2f	(-5.7637009404142,5.3755859061137)	;
glVertex2f	(-6.1501197559081,5.2688607094535)	;
glVertex2f	(-6.4960566002551,5.158455333598)	;
glVertex2f	(-6.7759875835183,5.0358620976017)	;
glVertex2f	(-7.1067485707226,4.915585374982)	;
glVertex2f	(-7.3387108214892,4.8081954440715)	;
glVertex2f	(-7.4890567247639,4.7308746938159)	;
glVertex2f	(-7.6737674059299,4.6406671518511)	;
glVertex2f	(-7.7639749478947,4.5848243877777)	;
glVertex2f	(-7.7553837534219,4.8081954440715)	;
glVertex2f	(-7.7210189755306,5.1217740423301)	;
glVertex2f	(-7.7038365865849,5.4396482378252)	;
glVertex2f	(-7.695245392112,5.7059752664832)	;
glVertex2f	(-7.695245392112,5.9851890868504)	;
glVertex2f	(-7.7038365865849,6.2042645459078)	;
glVertex2f	(-7.7210189755306,6.4534091856202)	;
glVertex2f	(-7.7382013644762,6.5994594916584)	;
glVertex2f	(-7.6216650260041,6.7376297026539)	;
glVertex2f	(-7.4412080774556,6.9496666171985)	;
glVertex2f	(-7.2833082474756,7.0895207523236)	;
glVertex2f	(-7.0802941803584,7.2790005482996)	;
glVertex2f	(-6.8908143843825,7.4233661071384)	;
glVertex2f	(-6.6517089275556,7.6128459031144)	;
glVertex2f	(-6.3720006573053,7.8293942413727)	;
glVertex2f	(-6.0922923870551,8.0324083084898)	;
glVertex2f	(-5.8622097776557,8.1903081384698)	;
glVertex2f	(-5.6005472022602,8.3482079684498)	;
glVertex2f	(-5.3794874402883,8.4835506798612)	;
glVertex2f	(-5.1358705597477,8.6098705438452)	;
glVertex2f	(-4.941879340058,8.7136332892606)	;
glVertex2f	(-4.7749566626506,8.7813046449664)	;
glVertex2f	(-4.5538969006786,8.9121359326641)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(-8.9210458829443,0.7874234906563)	;
glVertex2f	(-7.7639749478947,4.5848243877777)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(-6.8136580563908,-2.2495788403855)	;
glVertex2f	(-3.5781871707583,-1.1502301516179)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(-7.0155835902845,-6.092120066619)	;
glVertex2f	(-3.7514687094963,-8.5278700338128)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(-0.0977114062729,-7.550103994922)	;
glVertex2f	(0,-4)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(3.3138639271314,-8.6799696107345)	;
glVertex2f	(6.6383794903071,-6.1926879600929)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(6.6099083477046,-2.5052236731142)	;
glVertex2f	(3.2696746502463,-1.4014276346851)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(8.3894230637377,0.3447756269473)	;
glVertex2f	(7.2781041850784,4.0515175656814)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(3.880710427906,5.521915774936)	;
glVertex2f	(1.849862789432,2.858007947758)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(1.758607039958,8.139565133728)	;
glVertex2f	(-2.2697589034184,8.3821830037966)	;

glEnd();


glBegin(GL_LINES);
glVertex2f	(-4.4756382221009,5.6442389873619)	;
glVertex2f	(-2.1583753099439,2.9453809853466)	;

glEnd();

glPopMatrix();

}




void character() {

    glPushMatrix();
    glScaled(0.5,0.5,1);

body();
kepala();
mata();
rambut();
mulut();
sepatu();
tangan();
glPopMatrix();
}

void character2() {

    glPushMatrix();
    glScaled(-1,1,1);
    glScaled(0.5,0.5,1);
    //glTranslated(1100,-300,0);
body2();
kepala2();
mata2();
rambut2();
mulut2();
sepatu2();
tangan2();
glPopMatrix();
}


void permainan () {
    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(bot[4],bot[5],bot[6]);
character();

glPopMatrix();

glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(ball[4],ball[5],ball[6]);
bola();

glPopMatrix();

glPushMatrix();
    glColor3ub(255,0,0);
    glTranslatef(chara[4],chara[5],chara[6]);
character2();

glPopMatrix();

score1();
score2();
time();
}


void timer (int a)
{


    bot[8] = bot[0] + bot[4];
    bot[9] = bot[1] + bot[4];

    bot[10] = bot[2] + bot[5];
    bot[11] = bot[3] + bot[5];

    chara[8] = chara[0] + chara[4];
    chara[9] = chara[1] + chara[4];

    chara[10] = chara[2] + chara[5];
    chara[11] = chara[3] + chara[5];

    ball[4] += kecepatanX;
    ball[5] += kecepatanY;

    ball[8] = ball[0] + ball[4];
    ball[9] = ball[1] + ball[4];

    ball[10] = ball[2] + ball[5];
    ball[11] = ball[3] + ball[5];

    if (ball[8] < batas[0]) {
        kecepatanX = -kecepatanX;
        MessageBox(NULL, "Computer scores a point.\nPress OK to continue.", "Computer Scores", MB_OK);
        scorep2++;
        ball[4] = 0;
        ball[5] = -200;
    }

    if (ball[9] > batas[1]) {
        kecepatanX = -kecepatanX;
        MessageBox(NULL, "You score a point!\nPress OK to continue playing.", "You Score.", MB_OK);
        scorep1++;
        ball[4] = 0;
        ball[5] = -200;
    }

    if (ball[9] > bot[8] && ((ball[10] <= bot[11] && ball[10] >= bot[10]) || (ball[11] <= bot[11] && ball[11] >= bot[10])) ) {
        kecepatanX = -kecepatanX;
    }

    if (ball[8] < chara[9] && ((ball[10] <= chara[11] && ball[10] >= chara[10]) || (ball[11] <= chara[11] && ball[11] >= chara[10]))) {
        kecepatanX = -kecepatanX;

    }

    if (ball[10] < batas[2]) {
        kecepatanY = -kecepatanY;

    }

    if (ball[11] > batas[3]) {
        kecepatanY = -kecepatanY;
    }

    if (ball[4] > 0) {
        if (easy) {
            if  (ball[5] < bot[5]) {
            bot[5] -= 0.2f;
        } else if (ball[5] > bot[5]) {
            bot[5] += 0.2f;
        }
        } else if (medium) {
        if  (ball[5] < bot[5]) {
            bot[5] -= 0.4f;
        } else if (ball[5] > bot[5]) {
            bot[5] += 0.4f;
        }
        } else if (hard) {
        if  (ball[5] < bot[5]) {
            bot[5] -= 0.8f;
        } else if (ball[5] > bot[5]) {
            bot[5] += 0.8f;
        }
        }
    }


    if (up) {
        chara[5] += 6.0f;
        up = false;
    }

    if (down) {
        chara[5] -= 6.0f;
        down = false;
    }


    glutPostRedisplay();
    glutTimerFunc(1,timer,0);

}

void timerwaktu (int a) {
waktu--;
glutPostRedisplay();
    glutTimerFunc(1000,timerwaktu,0);

}


void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
if (play) {
    background();
    permainan();


} else if(abot) {
    about();

} else if (pilihlvl) {
    background();
    menulvl();
} else if (loadingg) {
loading();
}

else if (menuu) {
    background();
    menu();
}

if (waktu == 0) {
        Over = true;
    if (scorep1 > scorep2) {
        Win();
    } else if (scorep2 > scorep1) {
        Lose();
    }

    play = false;
    kecepatanX = 0.0f;
    kecepatanY = 0.0f;
    easy = false;
    medium = false;
    hard = false;
}

if (hard) {

    if(scorep2 == 3) {
        play = false;
        Over = true;
        Lose();
        }
}

 if (loadingtime == 11) {
                loadingg = false;
                play = true;

                if (first) {
                timer(1);
                timerwaktu(1);
                first = false;

            }

        ball[4] = 0.1;
        ball[5] = -200.1;
        bot[4] = 550.0;
        bot[5] = -200.1;
        chara[4] = -550.0;
        chara[5] = -200.1;
        waktu = 60;
        kecepatanX = -1.0f;
        kecepatanY = 0.8f;
        scorep1 = 0;
        scorep2 = 0;
        }

glFlush();
}


void timerloading (int a) {
loadingtime++;
glutPostRedisplay();
glutTimerFunc(1000,timerloading,0);

}

void keyboard(unsigned char key, int x, int y)
{

switch(key) {
case 'w' :
    up = true;
    break;
    case 's' :
    down = true;
    break;
case 13:
    if (menuu) {
            menuu =false;
if (panahpilih[5] == 0.0f) {
    pilihlvl = true;

    } else if (panahpilih[5] == -150.0f) {
       abot = true;

    } else if (panahpilih[5] == -300.0f) {
        exit(1);
    }
} else if (pilihlvl) {
    pilihlvl = false;
    loadingtime = 0;
    timerloading(1);

    if (panahpilih[5] == 0.0f) {
    easy = true;

    } else if (panahpilih[5] == -150.0f) {
       medium = true;

    } else if (panahpilih[5] == -300.0f) {
        hard = true;
    }

         loadingg = true;



} else if (Over) {
Over = false;
menuu = true;
}
    break;
case 27 :
    if (pilihlvl) {
        pilihlvl = false;
        menuu = true;

    } else if (abot) {
        abot = false;
        menuu = true;
    }
    break;
default:
break;
}
glutPostRedisplay();

}

void keyboardArah(int key, int x, int y) {
if (key==101) {

    if (panahpilih[5] == -150.0f) {
        panahpilih[5] = 0.0f;
    } else if (panahpilih[5] == -300.0f) {
        panahpilih[5] = -150.f;
    }

}

if (key==103) {

    if (panahpilih[5] == 0.0f) {
        panahpilih[5] = -150.0f;
    } else if (panahpilih[5] == -150.0f) {
        panahpilih[5] = -300.f;
    }

}


glutPostRedisplay();
}


void on_resize(int w,int h)  //Method untuk responsivenya silahkan langsung di copas aja gpp
{
    win_width = w;
    win_height = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    display(); // refresh window.
}

int main(int argc, char * argv[]) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
glutInitWindowPosition(0, 0);
glutCreateWindow("Kubus");

glClearColor( 0, 1, 1, 1.);
glutKeyboardFunc(keyboard);
glutSpecialFunc(keyboardArah);
glutDisplayFunc(display);
glutReshapeFunc(on_resize); //method responsive di call di sini
glutMainLoop();
return 0;

}
