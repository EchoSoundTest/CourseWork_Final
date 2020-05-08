#ifndef SETTINGS_H
#define SETTINGS_H

#define DEBUG
#define _PDEBUG

typedef struct {
	int map_length;
	int reprod_chance;
	int wolf_health;
	int rab1, rab2;
	int wlf_m1, wlf_m2;
	int wlf_f1, wlf_f2;
} Settings;

typedef Settings* pSettings;

pSettings SettingsInitialize();

#endif // !SETTINGS_H
