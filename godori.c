#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include <string.h>

#include <sys/types.h>
#include <dirent.h>

#include "godori.h"

int menu2;

void assign_card(void) {
	/* assign 48 cards */
	/* 1 , guang, hong, */
	card_info_list[0].num = 1;
	card_info_list[1].num = 1;
	card_info_list[2].num = 1;
	card_info_list[3].num = 1;
	card_info_list[0].type = guang;
	card_info_list[0].detail_type.GUANG = normal_guang;
	card_info_list[1].type = ddie;
	card_info_list[1].detail_type.GEUT = hong_dan;
	card_info_list[2].type = pie;
	card_info_list[2].detail_type.PIE = normal_pie;
	card_info_list[3].type = pie;
	card_info_list[3].detail_type.PIE = normal_pie;

	/* 2 , godori, hong, */
	card_info_list[4].num = 2;
	card_info_list[5].num = 2;
	card_info_list[6].num = 2;
	card_info_list[7].num = 2;
	card_info_list[4].type = geut;
	card_info_list[4].detail_type.GEUT = godori;
	card_info_list[5].type = ddie;
	card_info_list[5].detail_type.GEUT = hong_dan;
	card_info_list[6].type = pie;
	card_info_list[6].detail_type.PIE = normal_pie;
	card_info_list[7].type = pie;
	card_info_list[7].detail_type.PIE = normal_pie;

	/* 3 , guang, hong, */
	card_info_list[8].num = 3;
	card_info_list[9].num = 3;
	card_info_list[10].num = 3;
	card_info_list[11].num = 3;
	card_info_list[8].type = guang;
	card_info_list[8].detail_type.GUANG = normal_guang;
	card_info_list[9].type = ddie;
	card_info_list[9].detail_type.DDIE = hong_dan;
	card_info_list[10].type = pie;
	card_info_list[10].detail_type.PIE = normal_pie;
	card_info_list[11].type = pie;
	card_info_list[11].detail_type.PIE = normal_pie;

	/* 4 , godori, cho, */
	card_info_list[12].num = 4;
	card_info_list[13].num = 4;
	card_info_list[14].num = 4;
	card_info_list[15].num = 4;
	card_info_list[12].type = geut;
	card_info_list[12].detail_type.GEUT = godori;
	card_info_list[13].type = ddie;
	card_info_list[13].detail_type.DDIE = cho_dan;
	card_info_list[14].type = pie;
	card_info_list[14].detail_type.PIE = normal_pie;
	card_info_list[15].type = pie;
	card_info_list[15].detail_type.PIE = normal_pie;

	/* 5 , geut, cho, */
	card_info_list[16].num = 5;
	card_info_list[17].num = 5;
	card_info_list[18].num = 5;
	card_info_list[19].num = 5;
	card_info_list[16].type = geut;
	card_info_list[16].detail_type.GEUT = normal_geut;
	card_info_list[17].type = ddie;
	card_info_list[17].detail_type.DDIE = cho_dan;
	card_info_list[18].type = pie;
	card_info_list[18].detail_type.PIE = normal_pie;
	card_info_list[19].type = pie;
	card_info_list[19].detail_type.PIE = normal_pie;

	/* 6 , geut, cheong, */
	card_info_list[20].num = 6;
	card_info_list[21].num = 6;
	card_info_list[22].num = 6;
	card_info_list[23].num = 6;
	card_info_list[20].type = geut;
	card_info_list[20].detail_type.GEUT = normal_geut;
	card_info_list[21].type = ddie;
	card_info_list[21].detail_type.DDIE = cheong_dan;
	card_info_list[22].type = pie;
	card_info_list[22].detail_type.PIE = normal_pie;
	card_info_list[23].type = pie;
	card_info_list[23].detail_type.PIE = normal_pie;

	/* 7 , geut, cho, */
	card_info_list[24].num = 7;
	card_info_list[25].num = 7;
	card_info_list[26].num = 7;
	card_info_list[27].num = 7;
	card_info_list[24].type = geut;
	card_info_list[24].detail_type.GEUT = normal_geut;
	card_info_list[25].type = ddie;
	card_info_list[25].detail_type.DDIE = cho_dan;
	card_info_list[26].type = pie;
	card_info_list[26].detail_type.PIE = normal_pie;
	card_info_list[27].type = pie;
	card_info_list[27].detail_type.PIE = normal_pie;

	/* 8 , guang, godori, */
	card_info_list[28].num = 8;
	card_info_list[29].num = 8;
	card_info_list[30].num = 8;
	card_info_list[31].num = 8;
	card_info_list[28].type = guang;
	card_info_list[28].detail_type.GUANG = normal_guang;
	card_info_list[29].type = geut;
	card_info_list[29].detail_type.GEUT = godori;
	card_info_list[30].type = pie;
	card_info_list[30].detail_type.PIE = normal_pie;
	card_info_list[31].type = pie;
	card_info_list[31].detail_type.PIE = normal_pie;

	/* 9 , special(double_pie or geut), cheong_dan, */
	card_info_list[32].num = 9;
	card_info_list[33].num = 9;
	card_info_list[34].num = 9;
	card_info_list[35].num = 9;
	card_info_list[32].type = special;
	card_info_list[32].detail_type.SPECIAL = double_pie_geut;
	card_info_list[33].type = ddie;
	card_info_list[33].detail_type.DDIE = cheong_dan;
	card_info_list[34].type = pie;
	card_info_list[34].detail_type.PIE = normal_pie;
	card_info_list[35].type = pie;
	card_info_list[35].detail_type.PIE = normal_pie;

	/* 10 , geut, cheong_dan, */
	card_info_list[36].num = 10;
	card_info_list[37].num = 10;
	card_info_list[38].num = 10;
	card_info_list[39].num = 10;
	card_info_list[36].type = geut;
	card_info_list[36].detail_type.GEUT = normal_geut;
	card_info_list[37].type = ddie;
	card_info_list[37].detail_type.DDIE = cheong_dan;
	card_info_list[38].type = pie;
	card_info_list[38].detail_type.PIE = normal_pie;
	card_info_list[39].type = pie;
	card_info_list[39].detail_type.PIE = normal_pie;

	/* 11 , guang, double_pie, */
	card_info_list[40].num = 11;
	card_info_list[41].num = 11;
	card_info_list[42].num = 11;
	card_info_list[43].num = 11;
	card_info_list[40].type = guang;
	card_info_list[40].detail_type.GUANG = normal_guang;
	card_info_list[41].type = pie;
	card_info_list[41].detail_type.PIE = double_pie;
	card_info_list[42].type = pie;
	card_info_list[42].detail_type.PIE = normal_pie;
	card_info_list[43].type = pie;
	card_info_list[43].detail_type.PIE = normal_pie;

	/* 12 , bi_guang, geut, bi_dan, double_pie */
	card_info_list[44].num = 12;
	card_info_list[45].num = 12;
	card_info_list[46].num = 12;
	card_info_list[47].num = 12;
	card_info_list[44].type = guang;
	card_info_list[44].detail_type.GUANG = bi_guang;
	card_info_list[45].type = geut;
	card_info_list[45].detail_type.GEUT = normal_geut;
	card_info_list[46].type = ddie;
	card_info_list[46].detail_type.DDIE = bi_dan;
	card_info_list[47].type = pie;
	card_info_list[47].detail_type.PIE = double_pie;
}





void draw_card(WINDOW *win, CARD *card, int col, int row, int inverted) {
	if(!inverted)
		wattron(win, A_REVERSE);
	wmove(win, col, row);

	if(card == NULL) {
		/* draw null card */
		wprintw(win, "     ");
		wmove(win, col+1, row);
		wprintw(win, "     ");
		wmove(win, col+2, row);
		wprintw(win, "     ");
	}
	//ó��
	else {
		if(card->type == guang) {
			if(card->detail_type.GUANG == bi_guang)
				wprintw(win, "�� ");
			else if(card->detail_type.SPECIAL == empty && card->type == back)
				wprintw(win, "     ");
			else
				wprintw(win, "��   ");
		}
		//���⵵ �պ��� �ǿ�
		else if(card->type == geut || card->type == special || card->type == guk) {
			if(card->type == geut && card->detail_type.GEUT == godori) {
				if(card->num == 2)
					wprintw(win, "   ��");
				if(card->num == 4)
					wprintw(win, "   ��");
				if(card->num == 8)
					wprintw(win, "   ��");
			}
			else if(card->detail_type.SPECIAL == empty && card->type == back)
				wprintw(win, "     ");
			else
				wprintw(win, "   ��");
		}
		else
			wprintw(win, "     ");
		///�߰�
		wmove(win, col+1, row);
		if(card->detail_type.SPECIAL == empty && card->type == back)
			wprintw(win, "���� ");
		else
			wprintw(win, " %2d  ", card->num);
		//��
		wmove(win, col+2, row);

		if(card->type == ddie) {
			if(card->detail_type.DDIE == hong_dan)
				wprintw(win, "ȫ�� ");
			else if(card->detail_type.DDIE == cheong_dan)
				wprintw(win, "û�� ");
			else if(card->detail_type.DDIE == cho_dan)
				wprintw(win, "�ʴ� ");
			else if(card->detail_type.SPECIAL == empty && card->type == back)
				wprintw(win, "     ");
			else
				wprintw(win, "��   ");
		}
		else if(card->type == pie || card->type == special) {
			if(card->detail_type.PIE == normal_pie)
				wprintw(win, "   ��");
			else if(card->detail_type.SPECIAL == empty && card->type == back)
				wprintw(win, "     ");
			else
				wprintw(win, " ����");
		}
		else
			wprintw(win, "     ");
	}

	if(!inverted)
		wattroff(win, A_REVERSE);
}

void alloc(void) {
	/* alloc pointer to card list of board */
	godori_game.cards_on_board = (CARD**)malloc(sizeof(CARD*)*28);
	godori_game.remain_cards = (CARD**)malloc(sizeof(CARD*)*(TOTAL_CARDS-28));

	/* alloc pointer to card list of players*/
	godori_game.player1.card_list = (CARD**)malloc(sizeof(CARD*)*10);
	godori_game.player1.siezed_card_list = (CARD**)malloc(sizeof(CARD*)*TOTAL_CARDS);
	godori_game.player2.card_list = (CARD**)malloc(sizeof(CARD*)*10);
	godori_game.player2.siezed_card_list = (CARD**)malloc(sizeof(CARD*)*TOTAL_CARDS);
}

void ncurses_init(void) {
	/* ncurses ini. */
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
}

void draw_all_cards(void) {
	draw_card(stdscr, card_info_list, 1, 1, FALSE);
	draw_card(stdscr, card_info_list+1, 1, 7, FALSE);
	draw_card(stdscr, card_info_list+2, 1, 13, FALSE);
	draw_card(stdscr, card_info_list+3, 1, 19, FALSE);

	draw_card(stdscr, card_info_list+4, 1, 25, FALSE);
	draw_card(stdscr, card_info_list+5, 1, 31, FALSE);
	draw_card(stdscr, card_info_list+6, 1, 37, FALSE);
	draw_card(stdscr, card_info_list+7, 1, 43, FALSE);

	draw_card(stdscr, card_info_list+8, 1, 49, FALSE);
	draw_card(stdscr, card_info_list+9, 1, 55, FALSE);
	draw_card(stdscr, card_info_list+10, 1, 61, FALSE);
	draw_card(stdscr, card_info_list+11, 1, 67, FALSE);

	draw_card(stdscr, card_info_list+12, 5, 1, FALSE);
	draw_card(stdscr, card_info_list+13, 5, 7, FALSE);
	draw_card(stdscr, card_info_list+14, 5, 13, FALSE);
	draw_card(stdscr, card_info_list+15, 5, 19, FALSE);

	draw_card(stdscr, card_info_list+16, 5, 25, FALSE);
	draw_card(stdscr, card_info_list+17, 5, 31, FALSE);
	draw_card(stdscr, card_info_list+18, 5, 37, FALSE);
	draw_card(stdscr, card_info_list+19, 5, 43, FALSE);

	draw_card(stdscr, card_info_list+20, 5, 49, FALSE);
	draw_card(stdscr, card_info_list+21, 5, 55, FALSE);
	draw_card(stdscr, card_info_list+22, 5, 61, FALSE);
	draw_card(stdscr, card_info_list+23, 5, 67, FALSE);

	draw_card(stdscr, card_info_list+24, 9, 1, FALSE);
	draw_card(stdscr, card_info_list+25, 9, 7, FALSE);
	draw_card(stdscr, card_info_list+26, 9, 13, FALSE);
	draw_card(stdscr, card_info_list+27, 9, 19, FALSE);

	draw_card(stdscr, card_info_list+28, 9, 25, FALSE);
	draw_card(stdscr, card_info_list+29, 9, 31, FALSE);
	draw_card(stdscr, card_info_list+30, 9, 37, FALSE);
	draw_card(stdscr, card_info_list+31, 9, 43, FALSE);

	draw_card(stdscr, card_info_list+32, 9, 49, FALSE);
	draw_card(stdscr, card_info_list+33, 9, 55, FALSE);
	draw_card(stdscr, card_info_list+34, 9, 61, FALSE);
	draw_card(stdscr, card_info_list+35, 9, 67, FALSE);

	draw_card(stdscr, card_info_list+36, 13, 1, FALSE);
	draw_card(stdscr, card_info_list+37, 13, 7, FALSE);
	draw_card(stdscr, card_info_list+38, 13, 13, FALSE);
	draw_card(stdscr, card_info_list+39, 13, 19, FALSE);

	draw_card(stdscr, card_info_list+40, 13, 25, FALSE);
	draw_card(stdscr, card_info_list+41, 13, 31, FALSE);
	draw_card(stdscr, card_info_list+42, 13, 37, FALSE);
	draw_card(stdscr, card_info_list+43, 13, 43, FALSE);

	draw_card(stdscr, card_info_list+44, 13, 49, FALSE);
	draw_card(stdscr, card_info_list+45, 13, 55, FALSE);
	draw_card(stdscr, card_info_list+46, 13, 61, FALSE);
	draw_card(stdscr, card_info_list+47, 13, 67, FALSE);
}

void init(void) {
	godori_game.winner = 0;
	/* random number init. */	
	srand(time(NULL));

	/* memory allocation */
	alloc();

	/* ncurses init */
	ncurses_init();

	/* assign basic cards to card_info_list*/
	assign_card();

	/* initial screen draw all cards */
	draw_all_cards();

	/* output messages */
	wmove(stdscr, 18, 30);
	printw("   GODORI   ");
	wmove(stdscr, 19, 30);
	printw("    GAME   ");
	wmove(stdscr, 20, 30);
	printw("Press Any Key");
	refresh();
	getchar();

	update_display();
}

int get_cmd(void) {
	int key;
	int cmd = NOTHING;

	key = wgetch(stdscr);
	switch(key) {
	case 260:		/* LEFT key */
		strcpy(debug_msg, "KEY_LEFT");	
		if(godori_game.current_card > 0)
			godori_game.current_card--;
		break;
	case 261:		/* RIGHT key */
		strcpy(debug_msg, "KEY_RIGHT");
		if(godori_game.current_turn == 1) {
			if(godori_game.current_card < godori_game.player1.card_list_cnt - 1)
				godori_game.current_card++;
		}
		else {
			if(godori_game.current_card < godori_game.player2.card_list_cnt - 1)
				godori_game.current_card++;
		}
		break;
	case 10:		/* ENTER key */
		cmd = SELECT_CARD;
		break;
	case 118:	/* 'v' key */
		viewdata = 1;
		cmd = VIEW_CARD;
		break;
	case 113:	/* 'q' key */
		cmd = EXIT_PRGM;
		break;
	default:
		strcpy(debug_msg, "NOTHING");
		break;
	}

	return cmd;
}

void add_point_info(POINT *point, CARD *card) {

}

//������ �Ƿ�?
/*
{
//����(p1)
if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
refresh();
kuk = wgetch(stdscr);
switch(kuk){//board ���� �����з� �߰�
case 121://y
godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
break;
case 110://n
break;
}
}
//����(p2)
if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
refresh();
kuk = wgetch(stdscr);
switch(kuk){//board ���� �����з� �߰�
case 121://y
godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
break;
case 110://n
break;
}
}
}
*/

void same_card_match(CARD *player_card, CARD *opened_card, int mc, int *idx) {
	int kuk;
	int dx_total[48] = {0};
	int i,j,a,m,n;

	/*player1*/
	if(godori_game.current_turn == 1){

		if(mc == 0){//��
			//�����п� �߰�(�����)
			godori_game.player1.siezed_card_list_cnt++ ;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(�������)
			godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player1.card_list[godori_game.current_card];
			//����
			if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
			case 121://y
				godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
				godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie ;
				break;
			case 110://n
				break;
				}
			}

			godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
			for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
				if(i != godori_game.player1.card_list_cnt){
				godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
			}
			}

			//�����п� �߰�(deck)
			godori_game.remain_cards_cnt--;//������ ī�忡�� �����п� �߰� ��
			godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
			godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
			//����
			if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
			case 121://y
				godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
				godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie ;
				break;
			case 110://n
				break;
				}
			}

			//�������
			if(godori_game.player2.siezed_card_list_cnt != 0 && godori_game.player2.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
				godori_game.player1.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
				for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
					if(godori_game.player2.siezed_card_list[i]->type==pie ||godori_game.player2.siezed_card_list[i]->type==guk){
						godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player2.siezed_card_list[i];
						break;
					}
				}

				godori_game.player2.siezed_card_list_cnt--;//2�� ���� �� �� ����
				for( ; i<godori_game.player2.siezed_card_list_cnt ; i++)
					godori_game.player2.siezed_card_list[i] = godori_game.player2.siezed_card_list[i+1];
			}
		}
		else if(mc == 1){//�� 
			//���忡 �߰� (�����)
			godori_game.cards_on_board_cnt++;//board cnt ����
			godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.player1.card_list[godori_game.current_card];//board���߰�(�����

			godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
			for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//����� ī������(�������� ��ĭ�� ���)
				if(i != godori_game.player1.card_list_cnt){
				godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
			}
			}

			//���忡 �߰�(deck)
			godori_game.cards_on_board_cnt++;//board cnt ����
			godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt-1];//board���߰�(deck
			godori_game.remain_cards_cnt--;	//deck�� ī��� ����(remain �����)


		}
		else if(mc == 2){//����
			//�����(�����, ����, ������ �߰�)
			godori_game.player1.siezed_card_list_cnt++ ;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(�������)
			godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player1.card_list[godori_game.current_card];
			//����
			if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
				case 121://y
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie ;
					break;
				case 110://n
					break;
				}
			}

			godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
			for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
				if(i != godori_game.player1.card_list_cnt){
				godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
			}
			}

			//deck(�����, ������ �߰�)			
			godori_game.remain_cards_cnt--;//������ ī�忡�� �����п� �߰� ��
			godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
			godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
			//����
			if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
				case 121://y
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
					break;
				case 110://n
					break;
				}
			}

			//���⼭���ʹ� ���忡�� ����� ������ �ؾ� �ȴ�
			for(m=0 ; m<TOTAL_CARDS ; m++){//board �� ī�带 ���� �п� �߰�
				if(idx[m]==1){
					dx_total[m] = 1;
					godori_game.player1.siezed_card_list_cnt++;
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
					//����
					if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}
				}
			}
			//��������
			
			for(n=godori_game.cards_on_board_cnt-1 ; n >= 0 ;n--){
				if(idx[n]==1 ){
					godori_game.cards_on_board_cnt--;
					if(n != godori_game.cards_on_board_cnt){
					for(j=n ; j<godori_game.cards_on_board_cnt ; j++){
						godori_game.cards_on_board[j] = godori_game.cards_on_board[j+1];
					}
					}
				}
			}
			/*
			for(i=0 ;i<godori_game.cards_on_board_cnt-1 ;i++){
				for(j=0 ; j<godori_game.cards_on_board_cnt-1 ;j++){
					if(dx_total[i] >= dx_total[i+1]){
						tmpt[0] = godori_game.cards_on_board[i];
						godori_game.cards_on_board[i] = godori_game.cards_on_board[i+1];
						godori_game.cards_on_board[i+1] = tmpt[0];
					}

				}
			}*/
			/*
			for(i=0 ; i<godori_game.cards_on_board_cnt  ;i++){
				if(idx[i]==1){
					godori_game.cards_on_board_cnt--;
					if(idx[i+1]==1){
						for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
							godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
						}
						i--;
					}
					else{
						for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
							godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
						}

					}
				}
			}

*/



			//�������
			if(godori_game.player2.siezed_card_list_cnt != 0 && godori_game.player2.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
				godori_game.player1.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
				for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
					if(godori_game.player2.siezed_card_list[i]->type==pie||godori_game.player2.siezed_card_list[i]->type==guk){
						godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player2.siezed_card_list[i];
						break;
					}
				}

				godori_game.player2.siezed_card_list_cnt--;//2�� ���� �� �� ����
				for( ; i<godori_game.player2.siezed_card_list_cnt ; i++)
					godori_game.player2.siezed_card_list[i] = godori_game.player2.siezed_card_list[i+1];
			}
		}
	}
	/*player2*/
	else{
		if(mc == 0){//��
			//�����п� �߰�(�����)
			godori_game.player2.siezed_card_list_cnt++ ;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(�������)
			godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player2.card_list[godori_game.current_card];
			//����(p2)
			if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
				case 121://y
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
					break;
				case 110://n
					break;
				}
			}


			godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
			for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
				if(i != godori_game.player2.card_list_cnt){
				godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
			}
			}

			//�����п� �߰�(deck)
			godori_game.remain_cards_cnt--;//������ ī�忡�� �����п� �߰� ��
			godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
			godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
			//����(p2)
			if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
				case 121://y
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
					break;
				case 110://n
					break;
				}
			}

			//�������
			if(godori_game.player1.siezed_card_list_cnt != 0 && godori_game.player1.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
				godori_game.player2.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
				for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
					if(godori_game.player1.siezed_card_list[i]->type==pie || godori_game.player1.siezed_card_list[i]->type==guk){
						godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player1.siezed_card_list[i];
						break;
					}
				}

				godori_game.player1.siezed_card_list_cnt--;//1�� ���� �� �� ����
				for( ; i<godori_game.player1.siezed_card_list_cnt ; i++)
					godori_game.player1.siezed_card_list[i] = godori_game.player1.siezed_card_list[i+1];
			}
		}
		else if(mc == 1){//�� 
			
			//���忡 �߰� (�����)
			godori_game.cards_on_board_cnt++;//board cnt ����
			godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.player2.card_list[godori_game.current_card];//board���߰�(�����

			godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
			for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//����� ī������(�������� ��ĭ�� ���)
				if(i != godori_game.player2.card_list_cnt){
				godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
			}
			}

			//���忡 �߰�(deck)
			godori_game.cards_on_board_cnt++;//board cnt ����
			godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt-1];//board���߰�(deck
			godori_game.remain_cards_cnt--;	//deck�� ī��� ����(remain �����)

		}
		else if(mc == 2){//����
			//�����(�����, ����, ������ �߰�)
			godori_game.player2.siezed_card_list_cnt++ ;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(�������)
			godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player2.card_list[godori_game.current_card];
			//����(p2)
			if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
				case 121://y
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
					break;
				case 110://n
					break;
				}
			}

			godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
			for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
				if(i != godori_game.player2.card_list_cnt){
				godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
			}
			}

			//deck(�����, ������ �߰�)			
			godori_game.remain_cards_cnt--;//������ ī�忡�� �����п� �߰� ��
			godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
			godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
			//����(p2)
			if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
				mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
				refresh();
				kuk = wgetch(stdscr);
				switch(kuk){//board ���� �����з� �߰�
				case 121://y
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
					break;
				case 110://n
					break;
				}
			}

			//���⼭���ʹ� ���忡�� ����� ������ �ؾ� �ȴ�
			for(m=0 ; m<TOTAL_CARDS ; m++){//board �� ī�带 ���� �п� �߰�
				if(idx[m]==1){
					dx_total[m] = 1;
					godori_game.player2.siezed_card_list_cnt++;
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
					//����(p2)
					if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}
				}
			}
			//��������
			
			for(n=godori_game.cards_on_board_cnt-1 ; n >= 0 ;n--){
				if(idx[n]==1 ){
					godori_game.cards_on_board--;
					if(n != godori_game.cards_on_board_cnt){
						for(j=n ; j<godori_game.cards_on_board_cnt ; j++){
							godori_game.cards_on_board[j] = godori_game.cards_on_board[j+1];
						}
					}
				}
			}
			/*
			for(i=0 ;i<godori_game.cards_on_board_cnt-1 ;i++){
				for(j=0 ; j<godori_game.cards_on_board_cnt-1 ;j++){
					if(dx_total[i] >= dx_total[i+1]){
						tmpt[0] = godori_game.cards_on_board[i];
						godori_game.cards_on_board[i] = godori_game.cards_on_board[i+1];
						godori_game.cards_on_board[i+1] = tmpt[0];
					}

				}
			}*/

			/*
			for(i=0 ; i<godori_game.cards_on_board_cnt  ;i++){
				if(idx[i]==1){
					godori_game.cards_on_board_cnt--;
					if(idx[i+1]==1){
						for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
							godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
						}
						i--;
					}
					else{
						for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
							godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
						}

					}
				}
			}
*/


			//�������
			if(godori_game.player1.siezed_card_list_cnt != 0 && godori_game.player1.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
				godori_game.player2.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
				for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
					if(godori_game.player1.siezed_card_list[i]->type==pie || godori_game.player1.siezed_card_list[i]->type==guk){
						godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player1.siezed_card_list[i];
						break;
					}
				}

				godori_game.player1.siezed_card_list_cnt--;//1�� ���� �� �� ����
				for( ; i<godori_game.player1.siezed_card_list_cnt ; i++)
					godori_game.player1.siezed_card_list[i] = godori_game.player1.siezed_card_list[i+1];
			}
		}

	}

}

void diff_card_match(CARD *player_card, CARD *opened_card,  int mcp, int *idx1, int mco, int *idx2) {
	int kuk;
	int i,j,m,n,f,a, o;
	int key;
	int dx_total[TOTAL_CARDS] = {0};
	//int bd_cnt=0;

	/*
	for(i=0 ; i<TOTAL_CARDS ; i++){
	dx_total[i] = idx1[i];
	dx_total[i] = idx2[i];
	}
	*/
	//godori_game.current_card �� �״�� ���
	//�������� -1 ����� ���� �ʳ� ������(cnt �� �̿��� ���)


	/*player1*/	
	if(godori_game.current_turn == 1){
		for(a=0 ; a<2 ; a++){
			if(a==0){//����� ī��
				if(mcp==0){
					godori_game.cards_on_board_cnt++;//board cnt ����
					godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.player1.card_list[godori_game.current_card];//board���߰�(�����
				

					godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
					for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
						if(i != godori_game.player1.card_list_cnt )
						godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
					}

				}
				else if(mcp==1){
					if(bdx1[godori_game.current_card] != 1 && godori_game.player1.card_list[godori_game.current_card]->type != back){//.��ź�ƴ�
						//����
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx1[m]==1){
								dx_total[m] = 1;

								break;
							}
						}
						godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(����)
						godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
						//����(p1)
						if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
							mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
							refresh();
							kuk = wgetch(stdscr);
							switch(kuk){//board ���� �����з� �߰�
							case 121://y
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
								break;
							case 110://n
								break;
							}
						}

						//�����
						godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
						godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player1.card_list[godori_game.current_card];
						//����(p1)
						if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
							mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
							refresh();
							kuk = wgetch(stdscr);
							switch(kuk){//board ���� �����з� �߰�
							case 121://y
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
								break;
							case 110://n
								break;
							}
						}

					
					

						godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
						for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���,�����)
							if(i != godori_game.player1.card_list_cnt)
								godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
						}

					}
					else if(godori_game.player1.card_list[godori_game.current_card]->type == back){//�ں�°�
						godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
						for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
							if(i != godori_game.player1.card_list_cnt)
							godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
						}
					}
					else if(bdx1[godori_game.current_card] == 1){//��ź
						godori_game.player1.current_point.x_times_score *= 2;
						//����
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx1[m]==1){
								dx_total[m] = 1;

								break;
							}
						}
						godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(����)
						godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
						//����(p1)
						if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
							mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
							refresh();
							kuk = wgetch(stdscr);
							switch(kuk){//board ���� �����з� �߰�
							case 121://y
								godori_game.player1.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
								godori_game.player1.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
								break;
							case 110://n
								break;
							}
						}

						//�����п� ������� �Ǹ� �߰�
						for(i=0 ; i<godori_game.player1.card_list_cnt ;i++){
							if(bdx1[i]==1 && godori_game.player1.card_list[godori_game.current_card]->num == godori_game.player1.card_list[i]->num){//�����п� �߰� (����� �ڽ��� ���� ī��(��ź 3��))
								godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player1.card_list[i];
								//����(p1)
								if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
							}
						}
						for(i=0 ; i<godori_game.player1.card_list_cnt ; i++){//�������з� �ٲٱ�
							if(bdx1[i]==1 && i != godori_game.current_card && godori_game.player1.card_list[godori_game.current_card]->num == godori_game.player1.card_list[i]->num){
								godori_game.player1.card_list[i]->detail_type.SPECIAL = empty;
								godori_game.player1.card_list[i]->type = back;
								godori_game.player1.card_list[i]->num = 13;
							}
						}


						//����� ī�� ����
						for(i=godori_game.player1.card_list_cnt-1 ; i>=0 ;i--){
							if(bdx1[i]==1 && i == godori_game.current_card){
								godori_game.player1.card_list_cnt--;
								if(i != godori_game.player1.card_list_cnt){
									for(j=i ; j<godori_game.player1.card_list_cnt-1 ; j++){
										godori_game.player1.card_list[j] = godori_game.player1.card_list[j+1];
									}
								}
							}
						}
						/*
						godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
						for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���,�����)
						godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
						}
						*/

						//�������
						if(godori_game.player2.siezed_card_list_cnt != 0 && godori_game.player2.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
							godori_game.player1.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
							for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
								if(godori_game.player2.siezed_card_list[i]->type==pie || godori_game.player2.siezed_card_list[i]->type==guk){
									godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player2.siezed_card_list[i];
									break;
								}
							}

							godori_game.player2.siezed_card_list_cnt--;//2�� ���� �� �� ����
							for( ; i<godori_game.player2.siezed_card_list_cnt ; i++)
								godori_game.player2.siezed_card_list[i] = godori_game.player2.siezed_card_list[i+1];
						}


					}
				}
				else if(mcp==2){//���Ա�
					mvprintw(18,12, "���� �и� ������(������ : 1, �������� : 2)");
					refresh();
					key = wgetch(stdscr);
					switch(key){//board ���� �����з� �߰�
					case 49:
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx1[m]==1){
								dx_total[m] = 1;
								godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p1)
								if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					case 50:
						for(m=TOTAL_CARDS-1 ; m>=0 ;m--){
							if(idx1[m]==1){
								dx_total[m] = 1;
								godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p1)
								if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					}
					
					godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(�����)
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player1.card_list[godori_game.current_card];
					//����(p1)
					if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}

					godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
					for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
						if(i != godori_game.player1.card_list_cnt){
							godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
						}
					}

				}
				else if(mcp==3){//���徲��
					for(m=0 ; m<TOTAL_CARDS ; m++){//���� �п� �߰�
						if(idx1[m]==1){
							dx_total[m] = 1;
							godori_game.player1.siezed_card_list_cnt++;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
							//����(p1)
							if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
								mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
								refresh();
								kuk = wgetch(stdscr);
								switch(kuk){//board ���� �����з� �߰�
								case 121://y
									godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
									godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
									break;
								case 110://n
									break;
								}
							}
						}
					}
					
				

					godori_game.player1.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player1.card_list[godori_game.current_card];
					//����(p1)
					if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}

					godori_game.player1.card_list_cnt--;//����ڿ��� �����(cnt)
					for(i=godori_game.current_card ; i<godori_game.player1.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
						if(i != godori_game.player1.card_list_cnt){
						godori_game.player1.card_list[i] = godori_game.player1.card_list[i+1];
					}
					}

					//�������
					if(godori_game.player2.siezed_card_list_cnt != 0 && godori_game.player2.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
						godori_game.player1.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
						for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
							if(godori_game.player2.siezed_card_list[i]->type==pie || godori_game.player2.siezed_card_list[i]->type==guk){
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player2.siezed_card_list[i];
								break;
							}
						}

						godori_game.player2.siezed_card_list_cnt--;//2�� ���� �� �� ����
						for( ; i<godori_game.player2.siezed_card_list_cnt ; i++)
							godori_game.player2.siezed_card_list[i] = godori_game.player2.siezed_card_list[i+1];
					}


				}
			}
			else if(a==1){//�������� ī��
				if(mco==0){
					godori_game.cards_on_board_cnt++;//board cnt ����
					godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt-1];//board���߰�(deck
					godori_game.remain_cards_cnt--;	//deck�� ī��� ����												// �迭�� 0~19 ���� �����ؾߵ�

				}
				else if(mco==1){
					for(m=0 ; m<TOTAL_CARDS ;m++){
						if(idx2[m]==1){
							dx_total[m] = 1;
							godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
							//����(p1)
							if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
								mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
								refresh();
								kuk = wgetch(stdscr);
								switch(kuk){//board ���� �����з� �߰�
								case 121://y
									godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
									godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
									break;
								case 110://n
								break;
								}
							}
							break;
						}
					}

					godori_game.remain_cards_cnt--;//������ ī�忡��
					godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
					//����(p1)
					if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}

				}
				else if(mco==2){
					mvprintw(18,12, "���� �и� ������(������ : 1, �������� : 2)");
					refresh();
					key = wgetch(stdscr);
					switch(key){//board ���� �����з� �߰�
					case 49:
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx2[m]==1){
								dx_total[m] = 1;
								godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p1)
								if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					case 50:
						for(m=TOTAL_CARDS-1 ; m>=0 ;m--){
							if(idx2[m]==1){
								dx_total[m] = 1;
								godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p1)
								if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
										godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					}
					

					godori_game.remain_cards_cnt--;//������ ī�忡��
					godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
					//����(p1)
					if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}
				}
				else if(mco==3){//���徲��
					godori_game.remain_cards_cnt--;//������ ī�忡��
					godori_game.player1.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
					godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
					//����(p1)
					if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}

					for(m=0 ; m<TOTAL_CARDS ; m++){//���� �п� �߰�
						if(idx2[m]==1){
							dx_total[m] = 1;
							godori_game.player1.siezed_card_list_cnt++;
							godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
							//����(p1)
							if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
								mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
								refresh();
								kuk = wgetch(stdscr);
								switch(kuk){//board ���� �����з� �߰�
								case 121://y
									godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type = guk;
									godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
									break;
								case 110://n
									break;
								}
							}
						}
					}
				
					//�������
					if(godori_game.player2.siezed_card_list_cnt != 0 && godori_game.player2.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
						godori_game.player1.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
						for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
							if(godori_game.player2.siezed_card_list[i]->type==pie || godori_game.player2.siezed_card_list[i]->type==guk){
								godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player2.siezed_card_list[i];
								break;
							}
						}

						godori_game.player2.siezed_card_list_cnt--;//2�� ���� �� �� ����
						for( ; i<godori_game.player2.siezed_card_list_cnt ; i++)
							godori_game.player2.siezed_card_list[i] = godori_game.player2.siezed_card_list[i+1];
					}

				}
			}
		}

		//���⼭ ���������� ����. bd_cnt
		
		for(o=godori_game.cards_on_board_cnt-1 ; o>=0 ;o--){
			if(dx_total[o]==1){
				godori_game.cards_on_board_cnt--;
				if(o != godori_game.cards_on_board_cnt){
					for(j=o ; j<godori_game.cards_on_board_cnt ;j++)
						godori_game.cards_on_board[j] = godori_game.cards_on_board[j+1];		
				}

			}
		}

		/*
		for(i=0 ;i<godori_game.cards_on_board_cnt-1 ;i++){
			for(j=0 ; j<godori_game.cards_on_board_cnt-1 ;j++){
				if(dx_total[i] >= dx_total[i+1]){
					tmpt[0] = godori_game.cards_on_board[i];
					godori_game.cards_on_board[i] = godori_game.cards_on_board[i+1];
					godori_game.cards_on_board[i+1] = tmpt[0];
				}
				
			}
		}*/
		/*
		for(i=0 ; i<godori_game.cards_on_board_cnt  ;i++){
			if(dx_total[i]==1){
				godori_game.cards_on_board_cnt--;
				if(dx_total[i+1]==1){
					for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
						godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
					}
					i--;
				}
				else{
					for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
						godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
					}

				}
			}
		}
*/

		//�Ǿ���
		if(mcp==1 && mco ==1 && godori_game.cards_on_board == 0 && godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
			//�������
			if(godori_game.player2.siezed_card_list_cnt != 0 && godori_game.player2.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
				godori_game.player1.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
				for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
					if(godori_game.player2.siezed_card_list[i]->type==pie || godori_game.player2.siezed_card_list[i]->type==guk){
						godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1] = godori_game.player2.siezed_card_list[i];
						break;
					}
				}

				godori_game.player2.siezed_card_list_cnt--;//2�� ���� �� �� ����
				for( ; i<godori_game.player2.siezed_card_list_cnt ; i++)
					godori_game.player2.siezed_card_list[i] = godori_game.player2.siezed_card_list[i+1];
			}
		}
	}

	/*player2*/
	else{
		for(a=0 ; a<2 ; a++){
			if(a==0){
				//����� ī��
				if(mcp==0){
					godori_game.cards_on_board_cnt++;//board cnt ����
					godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.player2.card_list[godori_game.current_card];//board���߰�(�����

					godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
					for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
						if(i != godori_game.player2.card_list_cnt){
						godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
					}
					}

				}
				else if(mcp==1){
					if(bdx2[godori_game.current_card] != 1 && godori_game.player2.card_list[godori_game.current_card]->type != back){//.��ź�ƴ�)
						//�̰� ���忡 ������� �迭�� �߰� ����(dx_ total)
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx1[m]==1){
								dx_total[m] = 1;
								break;
							}
						}
						godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(����)
						godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
						//����(p2)
						if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
							mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
							refresh();
							kuk = wgetch(stdscr);
							switch(kuk){//board ���� �����з� �߰�
							case 121://y
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
								break;
							case 110://n
								break;
							}
						}

						//�����
						godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(�����)
						godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player2.card_list[godori_game.current_card];
						//����(p2)
						if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
							mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
							refresh();
							kuk = wgetch(stdscr);
							switch(kuk){//board ���� �����з� �߰�
							case 121://y
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
								break;
							case 110://n
								break;
							}
						}
						
						godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
						for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���,�����)
							if(i != godori_game.player2.card_list_cnt){
							godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
						}
						}
					}
					else if(godori_game.player2.card_list[godori_game.current_card]->type == back){
						godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
						for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
							if(i != godori_game.player2.card_list_cnt){
							godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
						}
						}
					}
					else if(bdx2[godori_game.current_card] == 1){//��ź
						godori_game.player2.current_point.x_times_score *= 2;
						//����
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx1[m]==1){
								dx_total[m] = 1;
								break;
							}
						}
						godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(����)
						godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
						//����(p1)
						if(godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player1.siezed_card_list[godori_game.player1.siezed_card_list_cnt-1]->type == special){
							mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
							refresh();
							kuk = wgetch(stdscr);
							switch(kuk){//board ���� �����з� �߰�
							case 121://y
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
								break;
							case 110://n
								break;
							}
						}

						//�����п� ������� �и� �߰�
						for(i=0 ; i<godori_game.player2.card_list_cnt ;i++){
							if(bdx2[i]==1&& godori_game.player2.card_list[godori_game.current_card]->num == godori_game.player2.card_list[i]->num){//�����п� �߰� (����� �ڽ��� ���� ī��(��ź 3��))
								godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player2.card_list[i];
								//����(p2)
								if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
							}
						}
						for(i=0 ; i<godori_game.player2.card_list_cnt ; i++){//�������з� �ٲٱ�
							if(bdx2[i]==1 && i != godori_game.current_card&& godori_game.player2.card_list[godori_game.current_card]->num == godori_game.player2.card_list[i]->num){
								godori_game.player2.card_list[i]->detail_type.SPECIAL = empty;
								godori_game.player2.card_list[i]->type = back;
								godori_game.player2.card_list[i]->num = 13;
							}
						}

						//����� ī�� ����
						for(i=godori_game.player2.card_list_cnt-1 ; i>=0 ;i--){
							if(bdx2[i]==1 && i == godori_game.current_card){
								godori_game.player2.card_list_cnt--;
								for(j=i ; j<godori_game.player2.card_list_cnt-1 ; j++){
									if(j != godori_game.player2.card_list_cnt){
									godori_game.player2.card_list[j] = godori_game.player2.card_list[j+1];
								}
								}
							}
						}
						

						//�������
						if(godori_game.player1.siezed_card_list_cnt != 0 && godori_game.player1.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
							godori_game.player2.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
							for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
								if(godori_game.player1.siezed_card_list[i]->type==pie || godori_game.player1.siezed_card_list[i]->type==guk){
									godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player1.siezed_card_list[i];
									break;
								}
							}

							godori_game.player1.siezed_card_list_cnt--;//1�� ���� �� �� ����
							for( ; i<godori_game.player1.siezed_card_list_cnt ; i++)
								godori_game.player1.siezed_card_list[i] = godori_game.player1.siezed_card_list[i+1];
						}
					}
				}
				else if(mcp==2){//��� �Ծ�� �� ���߿� ����.
					mvprintw(18,12, "���� �и� ������(������ : 1, �������� : 2)");
					refresh();
					key = wgetch(stdscr);
					switch(key){//board ���� �����з� �߰�
					case 49:
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx1[m]==1){
								dx_total[m] = 1;
								godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p2)
								if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					case 50:
						for(m=TOTAL_CARDS-1 ; m>=0 ;m--){
							if(idx1[m]==1){
								dx_total[m] = 1;
								godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p1)
								if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					}
					

					godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.(�����)
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player2.card_list[godori_game.current_card];
					//����(p2)
					if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}

					godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
					for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
						if(i != godori_game.player2.card_list_cnt){
						godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
					}
					}
				}
				else if(mcp==3){//���徲��
					for(m=0 ; m<TOTAL_CARDS ; m++){//���� �п� �߰�(����)
						if(idx1[m]==1){
							dx_total[m] = 1;
							godori_game.player2.siezed_card_list_cnt++;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
							//����(p2)
							if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
								mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
								refresh();
								kuk = wgetch(stdscr);
								switch(kuk){//board ���� �����з� �߰�
								case 121://y
									godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
									godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
									break;
								case 110://n
									break;
								}
							}
						}
					}

					
					godori_game.player2.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player2.card_list[godori_game.current_card];
					//����(p2)
					if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}

					godori_game.player2.card_list_cnt--;//����ڿ��� �����(cnt)
					for(i=godori_game.current_card ; i<godori_game.player2.card_list_cnt ; i++){//ī������(�������� ��ĭ�� ���)
						if(i != godori_game.player2.card_list_cnt){
						godori_game.player2.card_list[i] = godori_game.player2.card_list[i+1];
					}
					}
					//�������
					if(godori_game.player1.siezed_card_list_cnt != 0 && godori_game.player1.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
						godori_game.player2.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
						for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
							if(godori_game.player1.siezed_card_list[i]->type==pie || godori_game.player1.siezed_card_list[i]->type==guk){
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player1.siezed_card_list[i];
								break;
							}
						}

						godori_game.player1.siezed_card_list_cnt--;//1�� ���� �� �� ����
						for( ; i<godori_game.player1.siezed_card_list_cnt ; i++)
							godori_game.player1.siezed_card_list[i] = godori_game.player1.siezed_card_list[i+1];
					}

				}
			}
			else if(a==1){
				//�������� ī��
				if(mco==0){
					godori_game.cards_on_board_cnt++;//board cnt ����
					godori_game.cards_on_board[godori_game.cards_on_board_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt-1];//board���߰�(deck
					godori_game.remain_cards_cnt--;	//deck�� ī��� ����												// �迭�� 0~19 ���� �����ؾߵ�


				}
				else if(mco==1){
					for(m=0 ; m<TOTAL_CARDS ;m++){
						if(idx2[m]==1){//���忡�մ°� �Ծ��
							dx_total[m] = 1;
							godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
							//����(p2)
							if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
								mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
								refresh();
								kuk = wgetch(stdscr);
								switch(kuk){//board ���� �����з� �߰�
								case 121://y
									godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
									godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
									break;
								case 110://n
									break;
								}
							}
							break;
						}
					}

					godori_game.remain_cards_cnt--;//������ ī�忡��
					godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
					//����(p2)
					if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}
				

				}
				else if(mco==2){
					mvprintw(18,12, "���� �и� ������(������ : 1, �������� : 2)");
					refresh();
					key = wgetch(stdscr);
					switch(key){//board ���� �����з� �߰�
					case 49:	
						for(m=0 ; m<TOTAL_CARDS ;m++){
							if(idx2[m]==1){
								dx_total[m] = 1;
								godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p2)
								if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					case 50:
						for(m=TOTAL_CARDS-1 ; m>=0 ;m--){
							if(idx2[m]==1){
								dx_total[m] = 1;
								godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
								//����(p1)
								if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
									mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
									refresh();
									kuk = wgetch(stdscr);
									switch(kuk){//board ���� �����з� �߰�
									case 121://y
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
										godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
										break;
									case 110://n
										break;
									}
								}
								break;
							}
						}
						break;
					}

					godori_game.remain_cards_cnt--;//������ ī�忡��
					godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
					//����(p2)
					if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}
				}
				else if(mco==3){//���徲��
					godori_game.remain_cards_cnt--;//������ ī�忡��
					godori_game.player2.siezed_card_list_cnt++;//���� �� cnt ���� �ϰ� �����п� �߰� �Ѵ�.
					godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.remain_cards[godori_game.remain_cards_cnt];
					//����(p2)
					if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
						mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
						refresh();
						kuk = wgetch(stdscr);
						switch(kuk){//board ���� �����з� �߰�
						case 121://y
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
							break;
						case 110://n
							break;
						}
					}

					for(m=0 ; m<TOTAL_CARDS ; m++){//���� �п� �߰�
						if(idx2[m]==1){
							dx_total[m] = 1;
							godori_game.player2.siezed_card_list_cnt++;
							godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.cards_on_board[m];
							//����(p2)
							if(godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL == double_pie_geut &&godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type == special){
								mvprintw(40,8, "������ �Ƿ� ���ðڽ��ϱ�?(�Ƿ� ���� : y , ������ ���� : n)");
								refresh();
								kuk = wgetch(stdscr);
								switch(kuk){//board ���� �����з� �߰�
								case 121://y
									godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->type = guk;
									godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1]->detail_type.SPECIAL = double_pie;
									break;
								case 110://n
									break;
								}
							}
						}
					}
				
					//�������
					if(godori_game.player1.siezed_card_list_cnt != 0 && godori_game.player1.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
						godori_game.player2.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
						for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
							if(godori_game.player1.siezed_card_list[i]->type==pie || godori_game.player1.siezed_card_list[i]->type==guk){
								godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player1.siezed_card_list[i];
								break;
							}
						}

						godori_game.player1.siezed_card_list_cnt--;//1�� ���� �� �� ����
						for( ; i<godori_game.player1.siezed_card_list_cnt ; i++)
							godori_game.player1.siezed_card_list[i] = godori_game.player1.siezed_card_list[i+1];
					}

				}

			}
		}

		//���⼭���� ���������� ����

		for(o=godori_game.cards_on_board_cnt-1 ; o>=0 ;o--){
			if(dx_total[o]==1){
				godori_game.cards_on_board_cnt--;
				if(o != godori_game.cards_on_board_cnt){
					for(j=o ; j<godori_game.cards_on_board_cnt ;j++)
						godori_game.cards_on_board[j] = godori_game.cards_on_board[j+1];	
				}

			}
		}
		/*
		for(i=0 ;i<godori_game.cards_on_board_cnt-1 ;i++){
			for(j=0 ; j<godori_game.cards_on_board_cnt-1 ;j++){
				if(dx_total[i] >= dx_total[i+1]){
					tmpt[0] = godori_game.cards_on_board[i];
					godori_game.cards_on_board[i] = godori_game.cards_on_board[i+1];
					godori_game.cards_on_board[i+1] = tmpt[0];
				}

			}
		}*/
		/*
		for(i=0 ; i<godori_game.cards_on_board_cnt  ;i++){
			if(dx_total[i]==1){
				godori_game.cards_on_board_cnt--;
				if(dx_total[i+1]==1){
					for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
						godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
					}
					i--;
				}
				else{
					for(j=i ;j<godori_game.cards_on_board_cnt  ;j++){
						godori_game.cards_on_board[j]=godori_game.cards_on_board[j+1];
					}

				}
			}
		}*/

		//�Ǿ���
		if(mcp==1 && mco ==1 && godori_game.cards_on_board == 0 && godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
			//�������
			if(godori_game.player1.siezed_card_list_cnt != 0 && godori_game.player1.current_point.pie !=0&& godori_game.player1.card_list_cnt != 0 && godori_game.player2.card_list_cnt != 0){
				godori_game.player2.siezed_card_list_cnt++;//����ڰ� �� ī�忡�� �߰�
				for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
					if(godori_game.player1.siezed_card_list[i]->type==pie || godori_game.player1.siezed_card_list[i]->type==guk){
						godori_game.player2.siezed_card_list[godori_game.player2.siezed_card_list_cnt-1] = godori_game.player1.siezed_card_list[i];
						break;
					}
				}

				godori_game.player1.siezed_card_list_cnt--;//2�� ���� �� �� ����
				for( ; i<godori_game.player1.siezed_card_list_cnt ; i++)
					godori_game.player1.siezed_card_list[i] = godori_game.player1.siezed_card_list[i+1];
			}

		}
	}

}


void check_matching(CARD *player_card, CARD *opened_card) {

	int i,j,n;
	int matched_cnt_p = 0, matched_cnt_o = 0;
	int idx1[48];
	int idx2[48];
	//idx �� �ʱ�ȭ
	for(i=0 ; i<TOTAL_CARDS ; i++){
		*(idx1+i)=0;
		*(idx2+i)=0;
	}
	//bidx, bdx �ʱ�ȭ(bdx �� 0, 1 �θ� ���е�)
	for(i=0 ; i<10 ; i++){
		bidx1[i]=0;
		bidx2[i]=0;
		bdx1[i]=0;
		bdx2[i]=0;
	}


	/*��źüũ*/
	/*player1*/
	if(godori_game.current_turn == 1){
		for(i=0 ; i<godori_game.player1.card_list_cnt ; i++){
			bidx1[i] = godori_game.player1.card_list[i]->num;			
		}
		for(i=0 ; i<godori_game.player1.card_list_cnt ; i++){
			n=0;
			for(j=0 ; j<godori_game.player1.card_list_cnt ; j++){
				if(bidx1[i] == bidx1[j])
					n++;
			}
			if(n==3)
				bdx1[i] = 1;
		}

	}
	/*player2*/
	else{
		for(i=0 ; i<godori_game.player2.card_list_cnt ; i++){
			bidx2[i] = godori_game.player2.card_list[i]->num;			
		}
		for(i=0 ; i<godori_game.player2.card_list_cnt ; i++){
			n=0;
			for(j=0 ; j<godori_game.player2.card_list_cnt ; j++){
				if(bidx2[i] == bidx2[j])
					n++;
			}
			if(n==3)
				bdx2[i] = 1;
		}
	}

	/////////////////////////////////
	/*same*/
	if(player_card->num == opened_card->num){

		for(i=0 ; i<godori_game.cards_on_board_cnt ; i++){
			if(player_card->num == godori_game.cards_on_board[i]->num){
				matched_cnt_p++;
				idx1[i]=1;//board �� ��������ΰ�...
			}
		}
		//���⼭ ��ź�϶��� �׳��϶�
		same_card_match(player_card, opened_card, matched_cnt_p,idx1);
	}
	/*different*/
	else{
		//player card match cnt
		for(i=0 ; i<godori_game.cards_on_board_cnt ; i++){
			if(player_card->num == godori_game.cards_on_board[i]->num){
				matched_cnt_p++;
				idx1[i]=1;//board �� ��������ΰ�...
			}
		}
		//opened card match cnt
		for(i=0 ; i<godori_game.cards_on_board_cnt ; i++){
			if(opened_card->num == godori_game.cards_on_board[i]->num){
				matched_cnt_o++;
				idx2[i]=1;//board �� ��������ΰ�...
			}
		}

		//���⼭ ��ź�϶��� �׳��϶�
		diff_card_match(player_card, opened_card, matched_cnt_p , idx1, matched_cnt_o, idx2);
	}

	//////////////////////	
	/*��ź*/
	/*������*/




}

int select_card(void) {
	int i;
	//sprintf(debug_msg2, "[current_turn% 2d, current_card% 2d, remaincards% 2d]",godori_game.current_turn, godori_game.current_card,godori_game.remain_cards_cnt);
	//mvprintw(26,2,"[current_turn% 2d, current_card% 2d, remaincards% 2d]",godori_game.current_turn, godori_game.current_card,godori_game.remain_cards_cnt);
	for(i=0 ; i<godori_game.cards_on_board_cnt ; i++)
	mvprintw(27,2,"[%2d  ]",godori_game.cards_on_board[i]->num);
	refresh();
	if(godori_game.current_turn==1 && godori_game.player1.card_list_cnt > 1){
		check_matching(godori_game.player1.card_list[godori_game.current_card], godori_game.remain_cards[godori_game.remain_cards_cnt-1]);
		godori_game.current_card=0;
		return 0;

	}
	else if(godori_game.current_turn==2 && godori_game.player2.card_list_cnt > 1){//deck�� 19 ������
		check_matching(godori_game.player2.card_list[godori_game.current_card], godori_game.remain_cards[godori_game.remain_cards_cnt-1]);
		godori_game.current_card=0;
		return 0;
	}
	else if(godori_game.current_turn==1 && godori_game.player1.card_list_cnt == 1){
		check_matching(godori_game.player1.card_list[godori_game.current_card], godori_game.remain_cards[godori_game.remain_cards_cnt-1]);
		godori_game.current_card=0;

		if(godori_game.player1.card_list_cnt == 0 && godori_game.player2.card_list_cnt ==0)
			return 2;
		else
			return 0;
	}
	else if(godori_game.current_turn==2 && godori_game.player2.card_list_cnt == 1){
		check_matching(godori_game.player2.card_list[godori_game.current_card], godori_game.remain_cards[godori_game.remain_cards_cnt-1]);
		godori_game.current_card=0;

		if(godori_game.player1.card_list_cnt == 0 && godori_game.player2.card_list_cnt ==0)
			return 2;
		else
			return 0;
	}



}

void view_card(void) {
	int i, j;
	clear();
	refresh();

	/* draw player1's card */
	for(i = 0,j=0; i < godori_game.player1.siezed_card_list_cnt; i++) {
		//		if(i>9)
		//			break;
		if(godori_game.player1.siezed_card_list[i]->type == guang){
			draw_card(stdscr, godori_game.player1.siezed_card_list[i], 1, 1 + 6 * j, FALSE);
			j++;
		}
	}
	for(i=0,j = 0; i < godori_game.player1.siezed_card_list_cnt; i++/*,j++*/) {
		//		if(i > 19)
		//			break;
		if(godori_game.player1.siezed_card_list[i]->type == geut || godori_game.player1.siezed_card_list[i]->type == special){
			draw_card(stdscr,godori_game.player1.siezed_card_list[i], 5, 1 + 6 * j, FALSE);
			j++;
		}
	}
	for(i=0, j = 0 ; i < godori_game.player1.siezed_card_list_cnt ; i++/*,j++*/) {
		//if(j > 13)
		//	break;
		if(godori_game.player1.siezed_card_list[i]->type == ddie){
			draw_card(stdscr, godori_game.player1.siezed_card_list[i], 9, 1 + 6 * j, FALSE);
			j++;
		}
	}	
	for(i=0,j = 0; i < godori_game.player1.siezed_card_list_cnt; i++/*, j++*/) {
		if(j > 12)
			break;
		if(godori_game.player1.siezed_card_list[i]->type == pie ||godori_game.player1.siezed_card_list[i]->type == guk){
			draw_card(stdscr, godori_game.player1.siezed_card_list[i], 13, 1 + 6 * j, FALSE);
			j++;
		}
	}	
	for(j = 0; i < godori_game.player1.siezed_card_list_cnt; i++/*, j++*/) {
		if(godori_game.player1.siezed_card_list[i]->type == pie||godori_game.player1.siezed_card_list[i]->type == guk){
			draw_card(stdscr, godori_game.player1.siezed_card_list[i], 17, 1 + 6 * j, FALSE);
			j++;
		}
	}
	mvprintw(4,0,"��");
	mvprintw(8,0,"��");
	mvprintw(12,0,"��");
	mvprintw(16,0,"��");
	mvprintw(20,0,"��");
	mvprintw(20, 30, "player1 �� ������");
	refresh();

	/* draw player2's card */
	for(i = 0,j=0; i < godori_game.player2.siezed_card_list_cnt; i++) {
		//		if(i>9)
		//			break;
		if(godori_game.player2.siezed_card_list[i]->type == guang){
			draw_card(stdscr, godori_game.player2.siezed_card_list[i], 21, 1 + 6 * j, FALSE);
			j++;
		}
	}
	for(i=0, j = 0; i < godori_game.player2.siezed_card_list_cnt; i++) {
		//		if(i > 19)
		//			break;
		if(godori_game.player2.siezed_card_list[i]->type == geut || godori_game.player2.siezed_card_list[i]->type == special){
			draw_card(stdscr, godori_game.player2.siezed_card_list[i], 25, 1 + 6 * j, FALSE);
			j++;
		}
	}

	for(i=0, j = 0; i < godori_game.player2.siezed_card_list_cnt; i++) {
		//		if(i > 29)
		//			break;
		if(godori_game.player2.siezed_card_list[i]->type == ddie){
			draw_card(stdscr, godori_game.player2.siezed_card_list[i], 29, 1 + 6 * j, FALSE);
			j++;
		}
	}

	for(i=0,j = 0; i < godori_game.player2.siezed_card_list_cnt; i++) {
		if(j > 12)
			break;
		if(godori_game.player2.siezed_card_list[i]->type == pie || godori_game.player2.siezed_card_list[i]->type == guk){
			draw_card(stdscr, godori_game.player2.siezed_card_list[i], 33, 1 + 6 * j, FALSE);
			j++;
		}
	}

	for(j = 0; i < godori_game.player2.siezed_card_list_cnt; i++) {
		if(godori_game.player2.siezed_card_list[i]->type == pie || godori_game.player2.siezed_card_list[i]->type == guk){
			draw_card(stdscr, godori_game.player2.siezed_card_list[i], 37, 1 + 6 * j, FALSE);
			j++;
		}
	}
	mvprintw(24,0,"��");
	mvprintw(28,0,"��");
	mvprintw(32,0,"��");
	mvprintw(36,0,"��");
	mvprintw(40,0,"��");
	mvprintw(40, 30, "player2 �� ������");
	refresh();


}

int process_cmd(int cmd)
{
	switch(cmd) {
	case SELECT_CARD:
		return select_card();
		break;
	case VIEW_CARD:
		view_card();
		refresh();
		break;
	case EXIT_PRGM:
		return -1;
		break;
	case NOTHING:
	default:
		break;
	}
	return 1;//�̰� 0���� �ϰ� �׶�� �ȵ�
}

void draw_point_info(void)
{
	POINT *point;

	/* player 1 */
	point = &godori_game.player1.current_point;
	wmove(stdscr, 3, 61);
	wprintw(stdscr, "�����1 : %s",tmp);
	wmove(stdscr, 5, 61);
	wprintw(stdscr, "��[��]:%d[%d]", point->guang, point->bi_guang);
	wmove(stdscr, 6, 61);
	wprintw(stdscr, "��[����]:%d[%d]", point->geut, point->godori);
	wmove(stdscr, 7, 61);
	wprintw(stdscr, "��[ȫû��]:%d[%d:%d:%d]", point->ddie, point->hong_dan, point->cheong_dan, point->cho_dan);
	wmove(stdscr, 8, 61);
	wprintw(stdscr, "��:%d, ��:%d", point->pie, point->go);
	wmove(stdscr, 9, 61);
	wprintw(stdscr, "����:%d, %d��", point->total, point->x_times_score);

	/* player 2 */
	point = &godori_game.player2.current_point;
	wmove(stdscr, 15, 61);
	wprintw(stdscr, "��[��]:%d[%d]", point->guang, point->bi_guang);
	wmove(stdscr, 16, 61);
	wprintw(stdscr, "��[����]:%d[%d]", point->geut, point->godori);
	wmove(stdscr, 17, 61);
	wprintw(stdscr, "��[ȫû��]:%d[%d:%d:%d]", point->ddie, point->hong_dan, point->cheong_dan, point->cho_dan);
	wmove(stdscr, 18, 61);
	wprintw(stdscr, "��:%d, ��:%d", point->pie, point->go);
	wmove(stdscr, 19, 61);
	wprintw(stdscr, "����:%d, %d��", point->total, point->x_times_score);
	wmove(stdscr, 21, 61);
	wprintw(stdscr, "�����2 : %s",tmp3);

}

void update_display(void) {
	/* debug msg */
#if 1
	int i;
	char *mmsg = debug_msg;
	clear();
	refresh();
	wmove(stdscr, 15, 2);
	for(i = 0; i < godori_game.remain_cards_cnt; i++)
		sprintf(mmsg+i*3, "%d  ", godori_game.remain_cards[i]->num);

	wprintw(stdscr, mmsg);
	wmove(stdscr, 16, 2);//���� ����� �� ������ ��
	wprintw(stdscr, " [%d][����� %d:%d��° ��]", godori_game.remain_cards_cnt,	godori_game.current_turn, godori_game.current_card + 1);
	wmove(stdscr, 17, 2);
	wprintw(stdscr, debug_msg1);
	wmove(stdscr, 18, 2);
	wprintw(stdscr, debug_msg2);
	//if(godori_game.current_turn == 1){
//		wmove(stdscr, 17, 2);//����ڰ� �� ��
//		wprintw(stdscr, "[����ڰ� �� �� : %d ��]",godori_game.player1.card_list[godori_game.current_card]->num/*debug_msg1*/);
//	}
//	else{
//		wmove(stdscr, 17, 2);//����ڰ� �� ��
//		wprintw(stdscr, "[����ڰ� �� �� : %d ��]",godori_game.player2.card_list[godori_game.current_card]->num/*debug_msg1*/);
//	}
//	wmove(stdscr, 18, 2);//����� ���� ��
//	wprintw(stdscr, "[����� ���� �� : %d ��]",godori_game.remain_cards[godori_game.remain_cards_cnt]->num/*debug_msg2*/);

#else
	clear();
	refresh();
	wmove(stdscr, 16, 12);
	wprintw(stdscr, debug_msg);
	wprintw(stdscr, " [����� %d:%d��° ��]", 
		godori_game.current_turn, godori_game.current_card + 1);
	wmove(stdscr, 17, 12);
	wprintw(stdscr, debug_msg1);
	wmove(stdscr, 18, 12);
	wprintw(stdscr, debug_msg2);
#endif

	/* redraw current cards */
	draw_distrib_cards();

	/* draw point info */
	draw_point_info();

	refresh();

} 

void free_memory(void) {
	/* alloc pointer to card list of board */
	free(godori_game.cards_on_board);
	free(godori_game.remain_cards);

	/* alloc pointer to card list of players*/
	free(godori_game.player1.card_list);
	free(godori_game.player1.siezed_card_list);
	free(godori_game.player2.card_list);
	free(godori_game.player2.siezed_card_list);
}

void finalize(void) {
	clrtoeol();
	refresh();
	endwin();

	/* free memory */
	free_memory();
}

/* assign card info with random selection */
void shuffle_card(void) {
	int i,j,a;
	//���� ����
	for(i=0 ; i<TOTAL_CARDS ; i++){
		a = rand()%TOTAL_CARDS;
		shuffle[i] = a;
		for(j=0 ; j<i ; j++){
			if(shuffle[i] == shuffle[j]){
				i--;
				break;
			}

		}
	}
	//����ü���� ����
	for(i=0 ; i<TOTAL_CARDS ;i++){
		shuffled_cards[i] = card_info_list[shuffle[i]];
	}


}


void distrib_card(void) {
	int i;
	/* clear card list info. */

	for(i = 0; i < 28; i++) {
		refresh();
		godori_game.cards_on_board[i] = NULL;
		godori_game.player1.siezed_card_list[i] = NULL;
		godori_game.player2.siezed_card_list[i] = NULL;
	}
	for(; i < TOTAL_CARDS; i++) {
		godori_game.player1.siezed_card_list[i] = NULL;
		godori_game.player2.siezed_card_list[i] = NULL;
	}

	/* first five cards to player1 */
	godori_game.player1.card_list[0] = shuffled_cards;
	godori_game.player1.card_list[1] = shuffled_cards+1;
	godori_game.player1.card_list[2] = shuffled_cards+2;
	godori_game.player1.card_list[3] = shuffled_cards+3;
	godori_game.player1.card_list[4] = shuffled_cards+4;

	/* next five cards to player2 */
	godori_game.player2.card_list[0] = shuffled_cards+5;
	godori_game.player2.card_list[1] = shuffled_cards+6;
	godori_game.player2.card_list[2] = shuffled_cards+7;
	godori_game.player2.card_list[3] = shuffled_cards+8;
	godori_game.player2.card_list[4] = shuffled_cards+9;

	/* and then four cards to board */
	godori_game.cards_on_board[0] = shuffled_cards+10;
	godori_game.cards_on_board[1] = shuffled_cards+11;
	godori_game.cards_on_board[2] = shuffled_cards+12;
	godori_game.cards_on_board[3] = shuffled_cards+13;

	/* again, five cards to player1 */
	godori_game.player1.card_list[5] = shuffled_cards+14;
	godori_game.player1.card_list[6] = shuffled_cards+15;
	godori_game.player1.card_list[7] = shuffled_cards+16;
	godori_game.player1.card_list[8] = shuffled_cards+17;
	godori_game.player1.card_list[9] = shuffled_cards+18;

	/* next five cards to player2 */
	godori_game.player2.card_list[5] = shuffled_cards+19;
	godori_game.player2.card_list[6] = shuffled_cards+20;
	godori_game.player2.card_list[7] = shuffled_cards+21;
	godori_game.player2.card_list[8] = shuffled_cards+22;
	godori_game.player2.card_list[9] = shuffled_cards+23;

	/* lastly, four cards to board */
	godori_game.cards_on_board[4] = shuffled_cards+24;
	godori_game.cards_on_board[5] = shuffled_cards+25;
	godori_game.cards_on_board[6] = shuffled_cards+26;
	godori_game.cards_on_board[7] = shuffled_cards+27;

	/* save the remaining cards */
	for(i = 0; i < TOTAL_CARDS - 28; i++)
		godori_game.remain_cards[i] = shuffled_cards + 28 + i;

	godori_game.cards_on_board_cnt = 8;
	godori_game.remain_cards_cnt = TOTAL_CARDS - 28;
	godori_game.player1.card_list_cnt = 10;
	godori_game.player1.siezed_card_list_cnt = 0;
	godori_game.player2.card_list_cnt = 10;
	godori_game.player2.siezed_card_list_cnt = 0;
}

void draw_distrib_cards(void) {
	int i, j;

	/* draw player1's card */
	for(i = 0; i < godori_game.player1.card_list_cnt; i++) {
		draw_card(stdscr, godori_game.player1.card_list[i], 1, 1 + 6 * i, FALSE);
	}

	/* draw player2's card */
	for(i = 0; i < godori_game.player2.card_list_cnt; i++) {
		draw_card(stdscr, godori_game.player2.card_list[i], 21, 1 + 6 * i, FALSE);
	}

	/* draw cards on board */
	for(i = 0; i < godori_game.cards_on_board_cnt; i++) {
		if(i > 9)
			break;
		draw_card(stdscr, godori_game.cards_on_board[i], 5, 1 + 6 * i, FALSE);
	}

	for(j = 0; i < godori_game.cards_on_board_cnt; i++, j++) {
		if(i > 19)
			break;
		draw_card(stdscr, godori_game.cards_on_board[i], 9, 1 + 6 * j, FALSE);
	}

	for(j = 0; i < godori_game.cards_on_board_cnt; i++, j++) {
		if(i > 29)
			break;
		draw_card(stdscr, godori_game.cards_on_board[i], 13, 1 + 6 * j, FALSE);
	}

	for(j = 0; i < godori_game.cards_on_board_cnt; i++, j++) {
		draw_card(stdscr, godori_game.cards_on_board[i], 17, 1 + 6 * j, FALSE);
	}

	/* draw remain card */
	if(godori_game.remain_cards > 0) {
		draw_card(stdscr, NULL, 11, 65, FALSE);
	}

	/* draw current selected card */
	if(godori_game.current_turn == 1) {
		draw_card(stdscr, godori_game.player1.card_list[godori_game.current_card], 
			1, 1 + 6 * godori_game.current_card, TRUE);
	}
	else {
		draw_card(stdscr, godori_game.player2.card_list[godori_game.current_card], 
			21, 1 + 6 * godori_game.current_card, TRUE);
	}
}

void init_godori_info(void) {
	if(game_cnt ==1){
		godori_game.current_turn = 1;
	}
	else if(game_cnt >1){
	if( godori_game.winner== 1)
		godori_game.current_turn = 1;
	else if(godori_game.winner == 2)
		godori_game.current_turn = 2;
	}

	godori_game.current_card = 0;
	/* initially no winner */
	godori_game.winner = 0;
	//�׷��� ���ӵ� ���ӿ��� ���ڰ� ó�� ������ ���� current_turn �� �ٲ� �ʿ䰡 ���� ��...	
	/* player 1 first */
	

	/* init. player 1's score */
	godori_game.player1.current_point.guang = 0;
	godori_game.player1.current_point.bi_guang = 0;

	godori_game.player1.current_point.godori = 0;
	godori_game.player1.current_point.geut = 0;

	godori_game.player1.current_point.hong_dan = 0;
	godori_game.player1.current_point.cheong_dan = 0;

	godori_game.player1.current_point.cho_dan = 0;
	godori_game.player1.current_point.ddie = 0;

	godori_game.player1.current_point.pie = 0;
	godori_game.player1.current_point.go = 0;
	godori_game.player1.current_point.total = 0;

	godori_game.player1.current_point.x_times_score = 1;

	/* init. player 2's score */
	godori_game.player2.current_point.guang = 0;
	godori_game.player2.current_point.bi_guang = 0;

	godori_game.player2.current_point.godori = 0;
	godori_game.player2.current_point.geut = 0;

	godori_game.player2.current_point.hong_dan = 0;
	godori_game.player2.current_point.cheong_dan = 0;

	godori_game.player2.current_point.cho_dan = 0;
	godori_game.player2.current_point.ddie = 0;

	godori_game.player2.current_point.pie = 0;
	godori_game.player2.current_point.go = 0;
	godori_game.player2.current_point.total = 0;

	godori_game.player2.current_point.x_times_score = 1;
}

/* check chongtong and so on... */
void check_card(void) {
	int i,j,n;
	int key;
	//�迭�� �ʱ�ȭ �Ѵ�
	for(i=0 ; i<12 ; i++){
		p1[i] = 0;
		p2[i] = 0;
		boardp[i] = 0;
	}
	/*
	for(i=0 ; i<10 ; i++){
	for(j= ; j<10 ; j++){
	if(godori_game.player1.card_list[i].num == godori_game.player1.card_list[j].num){
	for(n=0 ; n<12 ; n++){
	if(n == godori_game.player1.card_list[i].num){
	p1[n]++;
	}
	}
	}
	}
	}
	*/
	for(i=0 ; i<10 ; i++){
		for(n=0 ; n<12 ; n++){
			if(godori_game.player1.card_list[i]->num == n+1)
				p1[n]++;
			if(godori_game.player2.card_list[i]->num == n+1)
				p2[n]++;
		}
	}

	for(i=0 ; i<8 ; i++){
		for(n=0 ; n<12 ; n++){
			if(godori_game.cards_on_board[i]->num == n+1)
				boardp[n]++;
		}
	}
	//1p
	for(n=0 ; n<12 ; n++){
		//����
		if(p1[n] == 4){
			godori_game.player1.current_point.total = 7;
			wmove(stdscr,18,30);
			printw("1p ����");
			refresh();
			ch = 1;
		}
		//���?
		else if(p1[n] == 3){
			wmove(stdscr,18,30);
			printw("1p 3���ħ");
			mvprintw(19,30,"����:y, �׳�����:n");
			refresh();
			
			key = wgetch(stdscr);
			switch(key){
			case 121:
				godori_game.player1.current_point.x_times_score*=2;
				//p1_shake++;		
				break;
			case 110:
				break;
			}
			
		}
	}
	//2p
	for(n=0 ; n<12 ; n++){
		//����
		if(p2[n] == 4){
			godori_game.player2.current_point.total = 7;
			wmove(stdscr,18,30);
			printw("2p ����");
			refresh();
			ch =1;
		}
		//���?
		else if(p2[n] == 3){
			wmove(stdscr,18,30);
			printw("2p 3���ħ");
			mvprintw(19,30,"����:y, �׳�����:n");
			refresh();
			
			key = wgetch(stdscr);
			switch(key){
			case 121:
				godori_game.player2.current_point.x_times_score*=2;
				//p2_shake;
				break;
			case 110:
				break;
			}
			
		}
	}
	//board
	for(n=0 ; n<12 ; n++){
		//����
		if(boardp[n] == 4){
			if(godori_game.current_turn==1)
				godori_game.player1.current_point.total = 7;
			else
				godori_game.player2.current_point.total = 7;

			wmove(stdscr,18,30);
			printw("board ����");
			ch=1;
			refresh();
		}
		//���?
		/*
		else if(boardp[n] == 3){
			wmove(stdscr,18,30);
			printw("board 3���ħ");
			refresh();
		}*/
	}
}
void init_game(void) {
	/* set play order, init point .. */
	init_godori_info();

	/* shuffle cards */
	shuffle_card();

	/* distribute cards and clear another card list info*/
	distrib_card();

	/* draw all game screen */
	update_display();
	//p1_shake = 0;
	//p2_shake = 0;
	/* check chongtong and so on... */
	check_card();
}

/*
return 0:
return -1:	go / stop
*/
void calculate(CARD *card , int a){
	int i,j;
	/*
	for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++)
	calculate(godori_game.player1.siezed_card_list[i] , 1);
	*/
	/*player1*/
	if(a==1){
		//for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
		if(card->type == guang) {
			if(card->detail_type.GUANG == bi_guang){//��
				godori_game.player1.current_point.bi_guang++;
				godori_game.player1.current_point.guang++;
			}
			else//��
				godori_game.player1.current_point.guang++;				
		}
		else if(card->type == geut || card->type == special) {//��
			if(card->type == geut && card->detail_type.GEUT == godori){ //����
				godori_game.player1.current_point.godori++;
				godori_game.player1.current_point.geut++;
			}
			else if(card->type == special)
				godori_game.player1.current_point.geut++;
			else//�׳� ��
				godori_game.player1.current_point.geut++;
		}

		else if(card->type == ddie) {
			if(card->detail_type.DDIE == hong_dan){//ȫ��
				godori_game.player1.current_point.hong_dan++;
				godori_game.player1.current_point.ddie++;				
			}
			else if(card->detail_type.DDIE == cheong_dan){//û��
				godori_game.player1.current_point.cheong_dan++;
				godori_game.player1.current_point.ddie++;
			}
			else if(card->detail_type.DDIE == cho_dan){//�ʴ�
				godori_game.player1.current_point.cho_dan++;
				godori_game.player1.current_point.ddie++;
			}
			else//�׳ɶ�
				godori_game.player1.current_point.ddie++;
		}
		else if(card->type == pie || card->type == guk ) {//��
			if(card->detail_type.PIE == normal_pie)//�׳���
				godori_game.player1.current_point.pie++;
			else//����
				godori_game.player1.current_point.pie+=2;
		}

		////������ ���� ����� �ؾ� ���� �ʳ� ������
		//��
		if(godori_game.player1.current_point.pie >= 10)
			godori_game.player1.current_point.total += godori_game.player1.current_point.pie - 9;
		//��
		if(godori_game.player1.current_point.ddie >= 5)
			godori_game.player1.current_point.total += godori_game.player1.current_point.ddie -4;
		if(godori_game.player1.current_point.cho_dan==3)
			godori_game.player1.current_point.total += 3;
		if(godori_game.player1.current_point.hong_dan==3)
			godori_game.player1.current_point.total += 3;
		if(godori_game.player1.current_point.cheong_dan==3)
			godori_game.player1.current_point.total += 3;
		//��
		if(godori_game.player1.current_point.geut >= 5)
			godori_game.player1.current_point.total += godori_game.player1.current_point.geut-4;
		if(godori_game.player1.current_point.godori == 3)
			godori_game.player1.current_point.total += 5;
		//������ʹ� ���̴�
		if(godori_game.player1.current_point.guang >= 3){
			if(godori_game.player1.current_point.guang == 3){
				if(godori_game.player1.current_point.bi_guang == 1)
					godori_game.player1.current_point.total += 2;
				else
					godori_game.player1.current_point.total += 3;
			}
			else if(godori_game.player1.current_point.guang ==4)
				godori_game.player1.current_point.total +=4;
			else if(godori_game.player1.current_point.guang ==5)
				godori_game.player1.current_point.total +=15;
		}
		//	}


	}
	/*player2*/
	else if(a==2){
		//for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
		if(card->type == guang) {
			if(card->detail_type.GUANG == bi_guang){//��
				godori_game.player2.current_point.bi_guang++;
				godori_game.player2.current_point.guang++;
			}
			else//��
				godori_game.player2.current_point.guang++;				
		}
		else if(card->type == geut || card->type == special) {//��
			if(card->type == geut && card->detail_type.GEUT == godori){ //����
				godori_game.player2.current_point.godori++;
				godori_game.player2.current_point.geut++;
			}
			else if(card->type == special)
				godori_game.player2.current_point.geut++;
			else//�׳� ��
				godori_game.player2.current_point.geut++;
		}

		else if(card->type == ddie) {
			if(card->detail_type.DDIE == hong_dan){//ȫ��
				godori_game.player2.current_point.hong_dan++;
				godori_game.player2.current_point.ddie++;				
			}
			else if(card->detail_type.DDIE == cheong_dan){//û��
				godori_game.player2.current_point.cheong_dan++;
				godori_game.player2.current_point.ddie++;
			}
			else if(card->detail_type.DDIE == cho_dan){//�ʴ�
				godori_game.player2.current_point.cho_dan++;
				godori_game.player2.current_point.ddie++;
			}
			else//�׳ɶ�
				godori_game.player2.current_point.ddie++;
		}
		else if(card->type == pie || card->type == guk/*|| card->type == special*/) {//��
			if(card->detail_type.PIE == normal_pie)//�׳���
				godori_game.player2.current_point.pie++;
			else//����
				godori_game.player2.current_point.pie+=2;
		}
	}
	////������ ���� ����� �ؾ� ���� �ʳ� ������

	//��
	if(godori_game.player2.current_point.pie >= 10)
		godori_game.player2.current_point.total += godori_game.player2.current_point.pie - 9;
	//��
	if(godori_game.player2.current_point.ddie >= 5)
		godori_game.player2.current_point.total += godori_game.player2.current_point.ddie -4;
	if(godori_game.player2.current_point.cho_dan==3)
		godori_game.player2.current_point.total += 3;
	if(godori_game.player2.current_point.hong_dan==3)
		godori_game.player2.current_point.total += 3;
	if(godori_game.player2.current_point.cheong_dan==3)
		godori_game.player2.current_point.total += 3;
	//��
	if(godori_game.player2.current_point.geut >= 5)
		godori_game.player2.current_point.total += godori_game.player2.current_point.geut-4;
	if(godori_game.player2.current_point.godori == 3)
		godori_game.player2.current_point.total += 5;
	//������ʹ� ���̴�
	if(godori_game.player2.current_point.guang >= 3){
		if(godori_game.player2.current_point.guang == 3){
			if(godori_game.player2.current_point.bi_guang == 1)
				godori_game.player2.current_point.total += 2;
			else
				godori_game.player2.current_point.total += 3;
		}
		else if(godori_game.player2.current_point.guang ==4)
			godori_game.player2.current_point.total +=4;
		else if(godori_game.player2.current_point.guang ==5)
			godori_game.player2.current_point.total +=15;
		//	}


	}

}

int update_player_score(void) {//�� or ���� üũ
	int i;
	int gostop;
	int p1_point;
	int p2_point;

	b_po1 = godori_game.player1.current_point.total;
	b_po2 = godori_game.player2.current_point.total;

	/*player1*/
	if(godori_game.current_turn == 1){
		//������� �ՠ���
		//player1 �ʱ�ȭ
		godori_game.player1.current_point.guang = 0;
		godori_game.player1.current_point.bi_guang = 0;
		godori_game.player1.current_point.geut = 0;
		godori_game.player1.current_point.godori = 0;
		godori_game.player1.current_point.ddie = 0;
		godori_game.player1.current_point.hong_dan = 0;
		godori_game.player1.current_point.cheong_dan = 0;
		godori_game.player1.current_point.cho_dan = 0;
		godori_game.player1.current_point.pie = 0;
		godori_game.player1.current_point.total = 0;
		//player2 �ʱ�ȭ
		godori_game.player2.current_point.guang = 0;
		godori_game.player2.current_point.bi_guang = 0;
		godori_game.player2.current_point.geut = 0;
		godori_game.player2.current_point.godori = 0;
		godori_game.player2.current_point.ddie = 0;
		godori_game.player2.current_point.hong_dan = 0;
		godori_game.player2.current_point.cheong_dan = 0;
		godori_game.player2.current_point.cho_dan = 0;
		godori_game.player2.current_point.pie = 0;
		godori_game.player2.current_point.total = 0;

		for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
			godori_game.player1.current_point.total = 0;
			calculate(godori_game.player1.siezed_card_list[i] , 1);
			//calculate(godori_game.player2.siezed_card_list[i] , 2);
		}
		for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
			godori_game.player2.current_point.total = 0;
			//calculate(godori_game.player1.siezed_card_list[i] , 1);
			calculate(godori_game.player2.siezed_card_list[i] , 2);
		}


		//���� �����ؾ��ϴ� ���
		if(godori_game.player1.current_point.total >= 7 && godori_game.player1.card_list_cnt != 0 && godori_game.player1.current_point.total > b_po1){
			clear();
			refresh();
			mvprintw(4,10,"���Ծ ��!(g) // ����(s)");
			refresh();
			gostop=wgetch(stdscr);

			switch(gostop){
			case 103:
				//godori_game.player1.current_point.x_times_score++;
				godori_game.player1.current_point.go++;
				return 0;
			case 115:
				return -1;	
			}
			/*
			if(gostop == 103){//��
			godori_game.player1.current_point.x_times_score++;
			return 0;
			}
			if(gostop == 115)//����
			return -1;
			*/
		}
		//  ���̻� ���� �а� ������
		else if(godori_game.player1.card_list_cnt ==0 && godori_game.player2.card_list_cnt ==0){
			return -1;
		}		

		return 0;
	}

	/*player2*/
	else if(godori_game.current_turn == 2){
		//������� ����
		//player1 �ʱ�ȭ
		godori_game.player1.current_point.guang = 0;
		godori_game.player1.current_point.bi_guang = 0;
		godori_game.player1.current_point.geut = 0;
		godori_game.player1.current_point.godori = 0;
		godori_game.player1.current_point.ddie = 0;
		godori_game.player1.current_point.hong_dan = 0;
		godori_game.player1.current_point.cheong_dan = 0;
		godori_game.player1.current_point.cho_dan = 0;
		godori_game.player1.current_point.pie = 0;
		godori_game.player1.current_point.total = 0;
		//player2 �ʱ�ȭ
		godori_game.player2.current_point.guang = 0;
		godori_game.player2.current_point.bi_guang = 0;
		godori_game.player2.current_point.geut = 0;
		godori_game.player2.current_point.godori = 0;
		godori_game.player2.current_point.ddie = 0;
		godori_game.player2.current_point.hong_dan = 0;
		godori_game.player2.current_point.cheong_dan = 0;
		godori_game.player2.current_point.cho_dan = 0;
		godori_game.player2.current_point.pie = 0;
		godori_game.player2.current_point.total = 0;

		for(i=0 ; i<godori_game.player1.siezed_card_list_cnt ; i++){
			godori_game.player1.current_point.total = 0;
			calculate(godori_game.player1.siezed_card_list[i] , 1);
			//calculate(godori_game.player2.siezed_card_list[i] , 2);
		}
		for(i=0 ; i<godori_game.player2.siezed_card_list_cnt ; i++){
			godori_game.player2.current_point.total = 0;
			//calculate(godori_game.player1.siezed_card_list[i] , 1);
			calculate(godori_game.player2.siezed_card_list[i] , 2);
		}


		//����
		if(godori_game.player2.current_point.total >= 7 && godori_game.player2.card_list_cnt != 0&& godori_game.player2.current_point.total > b_po2){
			clear();
			refresh();
			mvprintw(4,10,"���Ծ ��!(g) // ����(s)");
			refresh();
			gostop=wgetch(stdscr);

			switch(gostop){
			case 103:
				//godori_game.player2.current_point.x_times_score++;
				godori_game.player2.current_point.go++;
				return 0;
			case 115:
				return -1;
			}

			/*

			if(gostop == 103){//��
			godori_game.player2.current_point.x_times_score++;
			return 0;
			}
			if(gostop == 115)//����
			return -1;
			*/

		}
		//  ���̻� ���� �а� ������
		else if(godori_game.player2.card_list_cnt ==0 && godori_game.player2.card_list_cnt ==0){
			return -1;
		}		

		return 0;

	}
}

int update_game(void) {

	int a;
	a = update_player_score();

	if(a==0){//�Ϲ����� ���(�� �ٲٱ�)

		if(godori_game.current_turn == 1)
			godori_game.current_turn = 2;
		else
			godori_game.current_turn = 1;

		return 0;	
	}

	else{//���� or ����ڰ� ���� �а� ����.(������ ����) : a�� return ���� -1 �̴�.
		return -1;
	}

	//��/���� ���� ������ ����ε�..

}

void show_game_score(void) {
	POINT *point;

	if(godori_game.player1.current_point.total > godori_game.player2.current_point.total && godori_game.player1.current_point.total >=7)
		godori_game.winner = 1;
	else if(godori_game.player1.current_point.total < godori_game.player2.current_point.total &&godori_game.player2.current_point.total>=7)
		godori_game.winner = 2;
	else
		godori_game.winner = 0;

	/* view final card info */
	view_card();
	/*player1 ��������*/
	if(godori_game.winner == 1){
		if(godori_game.player1.current_point.pie >= 10 && godori_game.player2.current_point.pie<=5)//�ǹ�
			godori_game.player1.current_point.x_times_score *= 2;
		if(godori_game.player1.current_point.guang >= 3 && godori_game.player2.current_point.guang == 0)//����
			godori_game.player1.current_point.x_times_score *= 2;
		if(godori_game.player1.current_point.geut >= 7 )//�۹�
			godori_game.player1.current_point.x_times_score *= 2;

		godori_game.player1.current_point.total *= godori_game.player1.current_point.x_times_score;
		godori_game.player1.current_point.total *= godori_game.x_times_game;//������
	}
	

	/*player2 ��������*/
	if(godori_game.winner == 2){
		if(godori_game.player2.current_point.pie >= 10 && godori_game.player1.current_point.pie<=5)//�ǹ�
			godori_game.player2.current_point.x_times_score *= 2;
		if(godori_game.player2.current_point.guang >= 3 && godori_game.player1.current_point.guang == 0)//����
			godori_game.player2.current_point.x_times_score *= 2;
		if(godori_game.player2.current_point.geut >= 7 )//�۹�
			godori_game.player2.current_point.x_times_score *= 2;

		godori_game.player2.current_point.total *= godori_game.player2.current_point.x_times_score;
		godori_game.player2.current_point.total *= godori_game.x_times_game;//������
	}
	

	/* player 1 */
	point = &godori_game.player1.current_point;
	wmove(stdscr, 9, 81);
	wprintw(stdscr, "��[��]:%d[%d]", point->guang, point->bi_guang);
	wmove(stdscr, 10, 81);
	wprintw(stdscr, "��[����]:%d[%d]", point->geut, point->godori);
	wmove(stdscr, 11, 81);
	wprintw(stdscr, "��[ȫû��]:%d[%d:%d:%d]", point->ddie, point->hong_dan, point->cheong_dan, point->cho_dan);
	wmove(stdscr, 12, 81);
	wprintw(stdscr, "��:%d, ��:%d", point->pie, point->go);
	wmove(stdscr, 13, 81);
	wprintw(stdscr, "����:%d, %d��", point->total, point->x_times_score);

	/* player 2 */
	point = &godori_game.player2.current_point;
	wmove(stdscr, 21, 81);
	wprintw(stdscr, "��[��]:%d[%d]", point->guang, point->bi_guang);
	wmove(stdscr, 22, 81);
	wprintw(stdscr, "��[����]:%d[%d]", point->geut, point->godori);
	wmove(stdscr, 23, 81);
	wprintw(stdscr, "��[ȫû��]:%d[%d:%d:%d]", point->ddie, point->hong_dan, point->cheong_dan, point->cho_dan);
	wmove(stdscr, 24, 81);
	wprintw(stdscr, "��:%d, ��:%d", point->pie, point->go);
	wmove(stdscr, 25, 81);
	wprintw(stdscr, "����:%d, %d��", point->total, point->x_times_score);

	wmove(stdscr, 42, 2);
	if(godori_game.winner == 1)
		wprintw(stdscr, " %s �¸�, %d ���Դϴ�.",tmp,godori_game.player1.current_point.total);
	else if(godori_game.winner == 2)
		wprintw(stdscr, " %s �¸�, %d ���Դϴ�.",tmp3,godori_game.player2.current_point.total);
	else if(godori_game.winner == 0)
		wprintw(stdscr, " ������");

	wmove(stdscr, 44, 2);
	wprintw(stdscr, "�����Ϸ��� z Ű�� ��������");
	refresh();


}

int main(int argc, char **argv) {
	int choice;
	int cmd;
	int ret;
	int k;

	do{
		choice = menu();

		switch(choice){
			case 1:
				getdata();
				break;
			case 2:
				login();
				break;
		}
	}while(player_check != 1);

	printf("\nThank you\n");

	init();
	godori_game.x_times_game = 1;
	clear();
	refresh();
MENU:
	mvprintw(9,10,"        1. Start Game \n");
	mvprintw(10,10,"        2. View Rank  \n");
	mvprintw(11,10,"        3. Game Rule  \n");
	mvprintw(12,10,"        4. End        \n");
	menu1=wgetch(stdscr);
	refresh();
	switch(menu1){
		case 49:
			init();
			while(1) {
INIT:


				
				if(nagari == 0)
					godori_game.x_times_game = 1;
				init_game();

				while(1) {
					cmd = get_cmd();
					ret = process_cmd(cmd);
					if(ret == -1) {
						goto GAME_EXIT;
					}
					else if(ret == 0) {
						/* update score & change turn and so on .. */
						if(update_game() == -1)
							break;
					}
					else if(ret == 2){
						update_game();
						if(godori_game.winner == 0){//������
							if(nagari < 4){
								godori_game.x_times_game *= 2;
								nagari++;
							}
							else{
								nagari = 0;
							}
							
						}
						break;
					}
					else if(ch == 1){
						if(godori_game.player1.current_point.total > godori_game.player2.current_point.total)
							getrank(tmp,godori_game.player1.current_point.total);
						else if(godori_game.player2.current_point.total > godori_game.player1.current_point.total)
							getrank(tmp3,godori_game.player2.current_point.total);
						clear();
						refresh();
						ch=0;
						goto MENU2;

					}




					if(viewdata == 1)
						k = wgetch(stdscr);
					if(k==118)
						viewdata = 0;

					if(viewdata==0)
						update_display();

				}

				/* ������ ���� */
				update_display();
				show_game_score();
				game_cnt++;
				k=121;
				while(k!=122)
					k=wgetch(stdscr);
				current = godori_game.current_turn;
				if(godori_game.player1.current_point.total > godori_game.player2.current_point.total)
					getrank(tmp,godori_game.player1.current_point.total);
				else if(godori_game.player2.current_point.total > godori_game.player1.current_point.total)
					getrank(tmp3,godori_game.player2.current_point.total);
				clear();
				refresh();
MENU2:


				mvprintw(9,10,"        1. Continue Game                                       \n");
				mvprintw(10,10,"        2. View Rank		                                     \n");
				mvprintw(11,10,"        3. End                                                \n");

				menu2=wgetch(stdscr);
				refresh();
				switch(menu2){
		case 49:
			goto INIT;
			break;
		case 50:
			viewrank();
			clear();
			refresh();
			goto MENU2;
			break;// rank �Լ� �ֱ�
		case 51:
			goto GAME_EXIT;
			break;
				}




			}


			//���⿡ ����ȭ���� ��� ��� ���� �ʳ� ������
			//	}

GAME_EXIT:
			finalize();

			return 0;
			break;
		case 50:
			viewrank();
			clear();
			refresh();
			goto MENU;
			break;
		case 51:
			rule();
			clear();
			refresh();
			goto MENU;
			break;
		case 52:
			goto GAME_EXIT;
			break;
			return 0;
	}
}




int menu(void){
	int j;

	printf("\n 1. ����ڵ�� ");
	printf("\n 2. �α��� ");
	printf("\n �����ϼ���: ");
	scanf("%d", &j);
	fflush(stdin);

	return j;
}

void getdata(void){

	int a;
	int i,j;
	int flag=0;
	printf("����ڵ�� ����Դϴ�.\n");

	char id_str[100][100];
	char pw_str[100][100];

	FILE* fp;
	fp=fopen("user.txt","a");
	fclose(fp);
	fp=fopen("user.txt","rb");

	for(i=0;i<100;i++){
		fscanf(fp,"%s %s\n",id_str[i],pw_str[i]);
	}
	fclose(fp);

	while(1){
		while(1){
			printf("�̸��� �Է��ϼ���: ");
			scanf("%s",log[top].Name);
			for(i=0;i<100;i++){
				if(strcmp(log[top].Name,id_str[i]) == 0){
					printf("That id already exists. Please REwrite your id that you want\n"); 
					flag = 1;
					break;
				}
			}

			if(flag !=1)
				break;
			flag=0;
		}

		if(!*log[top].Name) break;
		printf("��й�ȣ�� �Է��ϼ���: ");
		scanf("%s",log[top].password);
		printf("������ �Է��ϼ���: ");
		scanf("%s",log[top].sex);
		printf("���̸� �Է��ϼ���: ");
		scanf("%s",log[top].age);
		fp = fopen("user.txt","a");
		fprintf(fp,"%s %s %s %s\n",log[top].Name,log[top].password,log[top].sex,log[top].age);
		fclose(fp);
		top++;
		printf("\nDo you want to sigh up more ?(yes=1/no=2)\n");
		scanf("%d",&a);
		if(a==2)
			break;
	}
}



void login(void){

	char id_str[100][100];
	char pw_str[100][100];
	char tmp2[20];
	char tmp4[20];
	int i,j;
	int flag1 = 0 ;
	int flag2 = 0 ;
	int flag3 = 0 ;


	FILE* fp=fopen("user.txt","rb");
	for(i=0;i<100;i++){
		fscanf(fp,"%s %s\n",id_str[i],pw_str[i]);
	}
	fclose(fp);

	printf("\n******1P �����ϼ���******\n\n");

	while(1){
		printf("���̵� �Է��ϼ���!\n");
		scanf("%s", tmp);
		for(i=0;i<100;i++){
			if(!strcmp(id_str[i], tmp)){
				flag1 = 1;  break;
			}
		}
		if(flag1 == 1)
			break;
	}

	while(1){
		printf("��й�ȣ�� �Է��ϼ���!\n");
		scanf("%s", tmp2);

		if(!strcmp(pw_str[i], tmp2)){
			break;
		}
	}


	printf("���̵�� ��й�ȣ�� ��ġ�մϴ�.\n");

	printf("\n******2P �����ϼ���******\n\n");

	while(1){
		while(1){
			printf("���̵� �Է��ϼ���!\n");
			scanf("%s", tmp3);
			if(strcmp(tmp,tmp3) == 0){
				printf("CAUTION : YOU DID NOT LOGIN WITH SAME ID\n");
				flag3 = 1;
			}
			if( flag3 != 1)
				break;
			flag3 = 0;
		}

		for(j=0;j<100;j++){
			if(!strcmp(id_str[j], tmp3)){
				flag2 = 1;  break;
			}
		}
		if(flag2 == 1)
			break;
	}

	while(1){
		printf("��й�ȣ�� �Է��ϼ���!\n");
		scanf("%s", tmp4);

		if(!strcmp(pw_str[j], tmp4)){
			break;
		}
	}

	printf("���̵�� ��й�ȣ�� ��ġ�մϴ�.\n");
	player_check = 1;

}

void getrank(char* id,int score){


	FILE* filein;
	filein=fopen("rank.txt","a");

	fprintf(filein,"%s %d\n",id,score);

	fclose(filein);

}
void viewrank(){

	int i;
	int j,k;
	int l=0;
	int flag=0;

	FILE* fp;
	char user_str[100][100];
	char score_str[100][100];
	char sort1[100];
	char sort2[100];
	int temp_int;
	char temp_char;
	char one[10000];
	int a,b;
	int c=0;
	int d;
	int score_int[100]={0};

	fp=fopen("rank.txt","rb");
	for(i=0;i<100;i++){
		fscanf(fp,"%s %s\n",user_str[i],score_str[i]);

	}
	fclose(fp);



	for(a=0;a<100;a++){
		for(b=0;b<100;b++){
			one[c] =user_str[a][b];
			c++;
		}
	}

	//	printf("%c %c\n",one[1],one[101]);

	//	 printf("%s %s %s\n",score_str[0],score_str[1],score_str[2]);
	for(a=0;a<100;a++){
		score_int[a] = atoi(score_str[a]);
		if(score_int[a] == 0)
			break;
	}


	for(j=0;j<a;j++){
		for(k=0;k<a;k++){
			if(score_int[k]<score_int[k+1]){
				temp_int = score_int[k];
				score_int[k] = score_int[k+1];
				score_int[k+1] = temp_int;
				for(d=0;d<100;d++){
					temp_char = one[k*100+d];
					one[k*100+d]=one[(k+1)*100+d];
					one[(k+1)*100+d] = temp_char;
				}
			}

		}
	}




	clear();
	refresh();

	c=0;

	for(a=0;a<100;a++){
		for(b=0;b<100;b++){
			user_str[a][b]=one[c];
			c++;
		}
	}


	mvprintw(5,5,"Rank");
	mvprintw(7,5,"1��  %s__ %d��",user_str[0],score_int[0]);
	mvprintw(8,5,"2��  %s__ %d��",user_str[1],score_int[1]);
	mvprintw(9,5,"3��  %s__ %d��",user_str[2],score_int[2]);


	refresh();
	sleep(1);

}

void rule()
{
	mvprintw(0, 5,"============================== G O D O R I ===============================\n"); // 30, 30
	mvprintw(1, 5,"|                                                                         |\n");
	mvprintw(2, 5,"| �� ����ڰ� �����ư��� ������ �ִ� �и� ���� �׿��ִ� ������ �п� �Բ�  |\n");
	mvprintw(3, 5,"| �ٴڿ� ��� �ִ� �и� ���Ͽ� ��ġ�� ��� �и� �������ϴ�.             |\n");
	mvprintw(4, 5,"|                                                                         |\n");
	mvprintw(5, 5,"|               *** �� ���� ������ ������ �����ϴ� ***                    |\n");
	mvprintw(6, 5,"|    1�� (����)    - ��, ȫ��, ��, ��                                     |\n");
	mvprintw(7, 5,"|    2�� (����)    - ��, ȫ��, ��, ��                                     |\n");
	mvprintw(8, 5,"|    3�� (����)    - ��, ȫ��, ��, ��                                     |\n");
	mvprintw(9, 5,"|    4�� (��θ�)  - ��, �ʴ�, ��, ��                                     |\n");
	mvprintw(10,5,"|    5�� (����)    - ��, �ʴ�, ��, ��                                     |\n");
	mvprintw(11, 5,"|    6�� (���)    - ��, û��, ��, ��                                     |\n");
	mvprintw(12, 5,"|    7�� (ȫ�θ�)  - ��, �ʴ�, ��, ��                                     |\n");
	mvprintw(13, 5,"|    8�� (����)    - ��, ��, ��, ��                                       |\n");
	mvprintw(14, 5,"|    9�� (����)    - ����, û��, ��, ��                                   |\n");
	mvprintw(15, 5,"|    10��(��ǳ)    - ��, û��, ��, ��                                     |\n");
	mvprintw(16, 5,"|    11��(����)    - ��, ����, ��, ��                                     |\n");
	mvprintw(17, 5,"|    12��(��)      - ��, ��, ��, ����                                   |\n");
	mvprintw(18, 5,"|                                                                         |\n");
	mvprintw(19, 5,"|               *** ������ ������ ���� ��� �մϴ� ***                    |\n");
	mvprintw(20, 5,"|    �� 3�� = 3�� (�� ���Խ� 2��)    | �� 4�� = 4�� | �� 5�� = 15��     |\n");
	mvprintw(21, 5,"|    �� 5�� = 1�� (�߰��� �� ��� 1��) | ����(2,4,8) 3�� = 5��          |\n");
	mvprintw(22, 5,"|    �� 5�� = 1�� (�߰��� �� ��� 1��) | û,ȫ,�� �� 3�� = 3��            |\n");
	mvprintw(23, 5,"|    �� 10�� = 1�� (�߰��� �� ��� 1��)                                   |\n");
	mvprintw(24, 5,"|                                                                         |\n");
	mvprintw(25, 5,"|               *** ������ ��� ���� ������ �ι踦 �մϴ� ***             |\n");
	mvprintw(26, 5,"|    ������ - �� 3�� �� ���                                            |\n");
	mvprintw(27, 5,"|    �ǹ�   - �Ƿ� ������ ���� �� ���� ������ 5�� ������ ���             |\n");
	mvprintw(28, 5,"|    ����   - ������ ������ ���� �� ���� �ϳ��� ���� ���                 |\n");
	mvprintw(29, 5,"|    ���   - ���� ���� �а� 3�� ���� ���                                |\n");
	mvprintw(30, 5,"|    �۹�   - ������ 7�� �̻��� ���                                      |\n");
	mvprintw(31, 5,"|                                                                         |\n");
	mvprintw(32, 5,"|               *** ������ ��� ������ �� �� ���� ���Ѿ� �ɴϴ�***      |\n");
	mvprintw(33, 5,"|  �Ǿ���   - ����ڰ� �ٴ��� �е��� ��� ������ ���                     |\n");
	mvprintw(34, 5,"|  ���徲�� - �ٴڿ� ������ ���̰� 3�� ���� �� �̸� �Դ� ���             |\n");
    mvprintw(35, 5,"|  ����     - �ٴڿ� ������ ���̰� 2�� ���� �� ����ڰ� �� �п�           |\n");
	mvprintw(36, 5,"|             ������ �а� ��� �ٴ��� 2��� ���� ���                     |\n");
	mvprintw(37, 5,"|  ��       - �ٴڿ� ���� ������ �и� �´µ� ������ ī��� ���� ���      |\n");
	mvprintw(38, 5,"|  ��ź     - ���� ������ �� 3���� �ѹ��� ���� �ٴ��� �и� ���� ���      |\n");
	mvprintw(39, 5,"|                                                                         |\n");
	mvprintw(40, 5,"===========================================================================\n");
	refresh();
	getchar();
}




