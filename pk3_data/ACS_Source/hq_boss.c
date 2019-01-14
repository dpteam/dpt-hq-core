#include "zcommon.acs"
#library "hq_boss"

// Boss #1 Music change events

script 1337 (void) NET
{
SetMusic("D_BOSS1",0);
}

script 1338 (void) NET
{
SetMusic("*",0);
}

// Boss #3 Music change events

script 1228 (void) NET
{
SetMusic("D_BOSS3",0);
}

script 1229 (void) NET
{
SetMusic("*",0);
}