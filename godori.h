#define TRUE 1
#define FALSE 0

#define TOTAL_CARDS	48

/* commands */
#define EXIT_PRGM	0
#define NOTHING		1
#define SELECT_CARD	2
#define VIEW_CARD	3

#define MAX 100

char debug_msg[256];
char debug_msg1[256];
char debug_msg2[256];
char debug_msg3[256];

int shuffle[TOTAL_CARDS];
int p1[12] = {0};
int p2[12] = {0};
int boardp[12] = {0};

int viewdata;
int gukjin=0;
int p1_turn=0;
int p2_turn=0;
//폭탄체크 idx
int bidx1[10] = {0};
int bidx2[10] = {0};
int bdx1[10] = {0};
int bdx2[10] = {0};

int nagari=0;
int p1_shake;
int p2_shake;

int b_po1;
int b_po2;

int game_cnt = 1;

struct service{
	    char Name[80];
        char password[20];
		char sex[20];
		char age[20];
}log[MAX];

int menu1,menu2;
int top = 0;
int check = 0;
int player_check = 0;
char* id;
int score;
char tmp[80],tmp3[80];
int menu(void);
void getdata(void);
void login(void);
void getrank(char* id,int score);
void viewrank();

int current=1;
int ch=0;
void rule();





/* 광/열끗/띠/피/특수 */
typedef enum  { guang, geut, ddie, pie, special, back ,guk} card_type;

/* 광/비광 */
typedef enum  { normal_guang, bi_guang } guang_type;

/* 열끗/고도리 */
typedef enum  { normal_geut, godori } geut_type;

/* 홍단/청단/초단/비띠 */
typedef enum  { hong_dan, cheong_dan, cho_dan, bi_dan } ddie_type;

/* 피/쌍피 */
typedef enum  { normal_pie, double_pie } pie_type;

/* 국진(쌍피 또는 열끗)/뒤집기 */
typedef enum  { double_pie_geut, empty } special_type;

typedef union { 
	guang_type GUANG;
	geut_type GEUT;
	ddie_type DDIE;
	pie_type PIE;
	special_type SPECIAL;
}card_spec;

/* 카드 정보 */
typedef struct card_info {
	int num;		/* 패 번호 */
	card_type type; 	/* 패 종류 */
	card_spec detail_type;	/* 패 세부종류 */
	int assigned;		/* whether current card info is assigned or not, 
							   when shuffled */ 
}CARD;


/* all basic card info */
CARD card_info_list[TOTAL_CARDS];

/* shuffled cards */
CARD shuffled_cards[TOTAL_CARDS];

/* 점수 정보 */
typedef struct point_info {
	int guang;		/* 광의 개수*/
	int bi_guang;		/* 비광 */

	int godori;		/* 고도리의 개수 */
	int geut;		/* 열끗의 개수 */

	int hong_dan;		/* 홍단의 개수 */
	int cheong_dan;		/* 청단의 개수 */
	int cho_dan;		/* 초단의 개수 */
	int ddie;		/* 띠의 개수 */ 

	int pie;		/* 피의 개수 */

	int go;			/* ‘고’한 횟수*/
	
	int total;		/* 총 점수 */
	int x_times_score;	/* 총 점수에 곱할 배수 */
}POINT;

/* 사용자 정보 */
typedef struct player_info {
	int total_point;	/* 총 점수 */
	POINT current_point;	/* 점수 정보 */
	CARD **card_list;	/* 갖고 있는 패 목록 */
	int card_list_cnt;	/* 갖고 있는 패의 개수 */
	CARD **siezed_card_list;	/* 먹은 패 목록 */
	int siezed_card_list_cnt;	/* 먹은 패의 개수 */
}PLAYER;

/* 고스톱 게임정보 */
typedef struct godori_info {
	int total_player;		/* 전체 사용자 명수, 여기서는 2 */
	PLAYER player1;			/* 사용자 1의 정보 */
	PLAYER player2;			/* 사용자 2의 정보 */
	CARD **cards_on_board;		/* 바닥에 깔린 패 목록 */
	int cards_on_board_cnt;		/* 바닥에 갈린 패의 개수 */
	CARD **remain_cards;		/* 뒤집혀 있는 패 목록 */
	int remain_cards_cnt;		/* 뒤집혀 있는 패의 개수 */
	
	int current_turn;		/* 현재 사용자 턴 */
	int current_card;		/* 현재 커서가 저장한 패 index */

	int winner;			/* 승리자 */
	
	int x_times_game;		/* x배 점수 게임 */
}GODORI_INFO;

/* 고스톱 게임정보를 저장하는 전역변수 */
GODORI_INFO godori_game;

/* function prototype */
void init();
void init_game();
int get_cmd();
int process_cmd(int cmd);
int update_game();
void show_game_score();
void update_display();
void draw_distrib_cards();
void finalize();
void calculate(CARD *card,int a);

CARD tmpt[1];

