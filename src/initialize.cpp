#include "main.h"

//V5 Brain display res:
//480 x 272 pixels

//Bool if using 2 or 1 contoller
int Acolor = -1;
int Aauton = 2;
bool duo = false;

static lv_res_t side_sel(lv_obj_t * sideBTNS, const char *txt){
	//occurs when side button are toggled
	if (strcmp(txt, "Main") == 0) {
		Aauton = 1;
	} else if (strcmp(txt, "Back") == 0){
		Aauton = 2;
	}	else if(strcmp(txt, "Skills") == 0){
		Aauton = 3;
	} else {
		Aauton = 0;
	}

  return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}

static lv_res_t col_sel(lv_obj_t * colorBTNS, const char *txt){
	//occurs when color buttons are toggled
	if (strcmp(txt, "Red") == 0) {
		Acolor = -1;
	} else if (strcmp(txt, "Blue") == 0){
		Acolor = 1;
	}	else {
		Acolor = -1;
	}

  return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}

static lv_res_t duo_sel(lv_obj_t * duoBTNS, const char *txt){
	//occurs when color buttons are toggled
	if (strcmp(txt, "Duo") == 0) {
		duo = true;
	} else if (strcmp(txt, "Solo") == 0){
		duo = false;
	}	else {
		duo = false;
	}

  return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}

static const char * btnm_side[] = {"Main", "Back", "Skills", ""};
static const char * btnm_color[] = {"Red", "Blue", ""};
static const char * btnm_duo[] = {"Duo", "Solo", ""};

void initialize() {
	//Background Style
	static lv_style_t style_bg;
	lv_style_copy(&style_bg, &lv_style_plain);
	style_bg.body.main_color = LV_COLOR_MAKE(0x35, 0x35, 0x35);
	style_bg.body.grad_color = LV_COLOR_MAKE(0x35, 0x35, 0x35);
	style_bg.body.padding.hor = 0;
	style_bg.body.padding.ver = 0;
	style_bg.body.padding.inner = 0;

	//Create 2 button styles
	static lv_style_t style_btn_rel;
	static lv_style_t style_btn_pr;
	lv_style_copy(&style_btn_rel, &lv_style_btn_rel);
	style_btn_rel.body.main_color = LV_COLOR_MAKE(0x65, 0x65, 0x65);//blackish
	style_btn_rel.body.grad_color = LV_COLOR_MAKE(0x65, 0x65, 0x65);
	style_btn_rel.body.border.color = LV_COLOR_MAKE(0x25, 0x25, 0x25);
	style_btn_rel.body.border.width = 1;
	style_btn_rel.body.border.opa = LV_OPA_100;
	style_btn_rel.body.radius = 0;

	lv_style_copy(&style_btn_pr, &style_btn_rel);
	style_btn_pr.body.main_color = LV_COLOR_MAKE(0x35, 0x35, 0x35);
	style_btn_pr.body.grad_color = LV_COLOR_MAKE(0x35, 0x35, 0x35);
	style_btn_pr.text.color = LV_COLOR_WHITE;

	//top matrix - side
	lv_obj_t * sideBTNS = lv_btnm_create(lv_scr_act(), NULL);
	lv_btnm_set_map(sideBTNS, btnm_side);
	lv_btnm_set_action(sideBTNS, side_sel); //action function
	lv_btnm_set_style(sideBTNS, LV_BTNM_STYLE_BG, &style_bg);
	lv_btnm_set_style(sideBTNS, LV_BTNM_STYLE_BTN_REL, &style_btn_rel);
	lv_btnm_set_style(sideBTNS, LV_BTNM_STYLE_BTN_PR, &style_btn_pr);
	lv_btnm_set_style(sideBTNS, LV_BTNM_STYLE_BTN_TGL_PR, &style_btn_pr);
	lv_btnm_set_style(sideBTNS, LV_BTNM_STYLE_BTN_TGL_REL, &style_btn_pr);
	lv_obj_set_size(sideBTNS, LV_HOR_RES, LV_VER_RES / 3);
	//Allow toggling
	for (std::size_t i = 0; i < 2; i++){
		lv_btnm_set_toggle(sideBTNS, true, i);
	}

	//bottom matrix - color
	lv_obj_t * colorBTNS = lv_btnm_create(lv_scr_act(), NULL);
	lv_btnm_set_map(colorBTNS, btnm_color);
	lv_btnm_set_action(colorBTNS, col_sel); //actino function
	lv_btnm_set_style(colorBTNS, LV_BTNM_STYLE_BG, &style_bg);
	lv_btnm_set_style(colorBTNS, LV_BTNM_STYLE_BTN_REL, &style_btn_rel);
	lv_btnm_set_style(colorBTNS, LV_BTNM_STYLE_BTN_PR, &style_btn_pr);
	lv_btnm_set_style(colorBTNS, LV_BTNM_STYLE_BTN_TGL_PR, &style_btn_pr);
	lv_btnm_set_style(colorBTNS, LV_BTNM_STYLE_BTN_TGL_REL, &style_btn_pr);
	lv_obj_set_size(colorBTNS, LV_HOR_RES, LV_VER_RES / 3);
	lv_obj_align(colorBTNS, sideBTNS, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	//Allow toggling
	for (std::size_t i = 0; i < 1; i++){
		lv_btnm_set_toggle(colorBTNS, true, i);
	}

	lv_obj_t * duoBTNS = lv_btnm_create(lv_scr_act(), NULL);
	lv_btnm_set_map(duoBTNS, btnm_duo);
	lv_btnm_set_action(duoBTNS, duo_sel); //action function
	lv_btnm_set_style(duoBTNS, LV_BTNM_STYLE_BG, &style_bg);
	lv_btnm_set_style(duoBTNS, LV_BTNM_STYLE_BTN_REL, &style_btn_rel);
	lv_btnm_set_style(duoBTNS, LV_BTNM_STYLE_BTN_PR, &style_btn_pr);
	lv_btnm_set_style(duoBTNS, LV_BTNM_STYLE_BTN_TGL_PR, &style_btn_pr);
	lv_btnm_set_style(duoBTNS, LV_BTNM_STYLE_BTN_TGL_REL, &style_btn_pr);
	lv_obj_set_size(duoBTNS, LV_HOR_RES, LV_VER_RES / 3);
	lv_obj_align(duoBTNS, colorBTNS, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	//Allow toggling
	for (std::size_t i = 0; i < 1; i++){
		lv_btnm_set_toggle(duoBTNS, true, i);
	}
}

void disabled() {
}

void competition_initialize() {
}
