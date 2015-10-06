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
//��źüũ idx
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





/* ��/����/��/��/Ư�� */
typedef enum  { guang, geut, ddie, pie, special, back ,guk} card_type;

/* ��/�� */
typedef enum  { normal_guang, bi_guang } guang_type;

/* ����/���� */
typedef enum  { normal_geut, godori } geut_type;

/* ȫ��/û��/�ʴ�/��� */
typedef enum  { hong_dan, cheong_dan, cho_dan, bi_dan } ddie_type;

/* ��/���� */
typedef enum  { normal_pie, double_pie } pie_type;

/* ����(���� �Ǵ� ����)/������ */
typedef enum  { double_pie_geut, empty } special_type;

typedef union { 
	guang_type GUANG;
	geut_type GEUT;
	ddie_type DDIE;
	pie_type PIE;
	special_type SPECIAL;
}card_spec;

/* ī�� ���� */
typedef struct card_info {
	int num;		/* �� ��ȣ */
	card_type type; 	/* �� ���� */
	card_spec detail_type;	/* �� �������� */
	int assigned;		/* whether current card info is assigned or not, 
							   when shuffled */ 
}CARD;


/* all basic card info */
CARD card_info_list[TOTAL_CARDS];

/* shuffled cards */
CARD shuffled_cards[TOTAL_CARDS];

/* ���� ���� */
typedef struct point_info {
	int guang;		/* ���� ����*/
	int bi_guang;		/* �� */

	int godori;		/* ������ ���� */
	int geut;		/* ������ ���� */

	int hong_dan;		/* ȫ���� ���� */
	int cheong_dan;		/* û���� ���� */
	int cho_dan;		/* �ʴ��� ���� */
	int ddie;		/* ���� ���� */ 

	int pie;		/* ���� ���� */

	int go;			/* ������ Ƚ��*/
	
	int total;		/* �� ���� */
	int x_times_score;	/* �� ������ ���� ��� */
}POINT;

/* ����� ���� */
typedef struct player_info {
	int total_point;	/* �� ���� */
	POINT current_point;	/* ���� ���� */
	CARD **card_list;	/* ���� �ִ� �� ��� */
	int card_list_cnt;	/* ���� �ִ� ���� ���� */
	CARD **siezed_card_list;	/* ���� �� ��� */
	int siezed_card_list_cnt;	/* ���� ���� ���� */
}PLAYER;

/* ���� �������� */
typedef struct godori_info {
	int total_player;		/* ��ü ����� ���, ���⼭�� 2 */
	PLAYER player1;			/* ����� 1�� ���� */
	PLAYER player2;			/* ����� 2�� ���� */
	CARD **cards_on_board;		/* �ٴڿ� �� �� ��� */
	int cards_on_board_cnt;		/* �ٴڿ� ���� ���� ���� */
	CARD **remain_cards;		/* ������ �ִ� �� ��� */
	int remain_cards_cnt;		/* ������ �ִ� ���� ���� */
	
	int current_turn;		/* ���� ����� �� */
	int current_card;		/* ���� Ŀ���� ������ �� index */

	int winner;			/* �¸��� */
	
	int x_times_game;		/* x�� ���� ���� */
}GODORI_INFO;

/* ���� ���������� �����ϴ� �������� */
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

