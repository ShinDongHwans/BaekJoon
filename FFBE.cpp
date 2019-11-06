#include<stdio.h>
#include<math.h>
#include<iostream>
#include<cstdlib>

class skill{
	private:
		char * name;
		char * element;
		char * kinds;
		int modify;
		
	public:
		void SkillSet(int _modify, char * _name, char * _element, char * _kinds);
		int Modify();
		char Element();
};

class unit{
	private:
		char * name;
		int Level = 1;
		int HP;
		int MAX_HP;
		int MP;
		int MAX_MP;
		int ATK;
		int DEF;
		int MAG;
		int SPR;
		int Fire_resistance;
		int Water_resistance;
		int Grass_resistance;
		int Light_resistance;
		int Dark_resistance;
		int EXP = 0;
		int Max_EXP = Level * 100;
		skill special_skill;
		
	public:
		void SetStat(char * _name, int _HP, int _MP, int _ATK, int _DEF, int _MAG, int _SPR, int _Fire_resistance, int _water_resistance, int _grass_resistance, int _light_resistance, int _dark_resistance);
		void SkillSetting(int _modify, char * _name, char * _element, char *kinds);
		void ShowStat();
		void ShowSkill();
		int Physical_Damage(skill _skill);
		void Check_EXP();
};

void unit::SetStat(char * _name, int _HP, int _MP, int _ATK, int _DEF, int _MAG, int _SPR, int _Fire_resistance, int _Water_resistance, int _Grass_resistance, int _Light_resistance, int _Dark_resistance){
	name = _name;
	HP = _HP;
	MAX_HP = _HP;
	MP = _MP;
	MAX_MP = _MP;
	ATK = _ATK;
	DEF = _DEF;
	MAG = _MAG;
	SPR = _SPR;
	Fire_resistance = _Fire_resistance;
	Water_resistance = _Water_resistance;
	Grass_resistance = _Grass_resistance;
	Light_resistance = _Light_resistance;
	Dark_resistance = _Dark_resistance;
}

void unit::SkillSetting(int _modify, char * _name, char * _element, char * _kinds){
	special_skill.SkillSet(_modify, _name, _element, _kinds);
}

void unit::ShowStat(){
	puts("=======================================");
	printf("Name: %s \nLevel: %d\n", name, Level);
	printf("EXP: %d/%d\n", EXP, Max_EXP);
	printf("HP: %d/%d   ", HP, MAX_HP);
	printf("MP: %d/%d\n", MP, MAX_MP);
	printf("ATK: %d       ", ATK);
	printf("MAG: %d\n", MAG);
	printf("DEF: %d       ", DEF);
	printf("SPR: %d\n", SPR);
	puts("=======================================");
}


int unit::Physical_Damage(skill _skill){
	int total_damage;
	total_damage = ATK*ATK/DEF*_skill.Modify();
	if(_skill.Element() == 'N')
		return total_damage;
	switch(_skill.Element()){
		case 'F':
			total_damage = total_damage/(1+Fire_resistance);
			break;
		case 'W':
			total_damage = total_damage/(1+Water_resistance);
			break;
		case 'G':
			total_damage = total_damage/(1+Grass_resistance);
			break;
		case 'L':
			total_damage = total_damage/(1+Light_resistance);
			break;
		case 'D':
			total_damage = total_damage/(1+Dark_resistance);
			break;
	}
	HP = HP - total_damage;
	return total_damage;
}



void skill::SkillSet(int _modify, char * _name, char * _element, char * _kinds){
	modify = _modify;
	name = _name;
	element = _element;
	kinds = _kinds;
}

int skill::Modify(){
	return modify;
}

char skill::Element(){
	return *element;
}

int main(){
	int i_for;
	int input=100;
	unit Hero;
	unit monster;
	char name[10];
	
	puts("=======================================");
	puts("=========Welcome to FFBE!!=============");	
	puts("=======================================");
	puts("If you want to start the game, press 1");	
	puts("=======================================");
	puts("If you want to finish the game, press 0");	
	puts("=======================================");
	while(input != 1 && input != 0){
		scanf("%d", &input);
	}
	if(input == 0){
		return 0;
	}
	selectinf_page:
	puts("=======================================");
	puts("==============1.New Start==============");	
	puts("=======================================");
	puts("==============2.Save game==============");
	puts("=======================================");
	for(;;){
		scanf("%d", &input);
		if(input == 1 || input ==2)
			break;
	}
	if(input == 1){
		puts("=======================================");
		puts("==========Make a name of Hero==========");
		puts("=======================================");
		
		gets(name);
		
		Job_Page:
		puts("=======================================");
		puts("============Select the Job=============");
		puts("=======================================");
		puts("===1. Warrior==========================");
		puts("===2. Maze=============================");
		puts("===3. Defender=========================");
		puts("===4. Healer===========================");
		puts("===5. Buffer===========================");
		puts("=======================================");
		scanf("%d", &input);
		switch(input){
			case 1:
				
				puts("=======================================");
				puts("=========Please tell your name=========");
				puts("=======================================");
				scanf("%s", &name);
				Hero.SetStat(name, 750, 50, 50, 30, 30, 30, 0, 0, 0, 0, 0);
				break;
			case 2:
				gets(name);
				Hero.SetStat(name, 500, 150, 10, 80, 10, 30, 0, 0, 0, 0, 0);
				break;
			case 3:
				gets(name);
				Hero.SetStat(name, 850, 50, 30, 10, 50, 40, 0, 0, 0, 0, 0);
				break;
			case 4:
				gets(name);
				Hero.SetStat(name, 600, 100, 10, 30, 20, 50, 0, 0, 0, 0, 0);
				break;
			case 5:
				gets(name);
				Hero.SetStat(name, 700, 100, 30, 30, 25, 25, 0, 0, 0, 0, 0);
				break;
			default:
				puts("=======================================");
				puts("===========Please press 1~5============");
				goto Job_Page;
		}
	}
	else{
		puts("=======================================");
		puts("================No Data================");
		goto selectinf_page;	
	}
		
	//after make new character
	Menu:
	puts("=======================================");
	puts("=================MENU==================");
	puts("=======================================");
	puts("============1.Unit=====================");
	puts("=======================================");
	puts("============2.Item=====================");
	puts("=======================================");
	puts("============3.Map======================");
	puts("=======================================");
	puts("============4.Turn Off=================");
	puts("=======================================");
	puts("============5.Settings=================");
	puts("=======================================");
	scanf("%d", &input);
	switch(input){
		case 1:
			Hero.ShowStat();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			return 0;
			break;
		default:
			goto Menu;
	}
}
