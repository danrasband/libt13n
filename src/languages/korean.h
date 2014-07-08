#ifndef __HANGUL_H__
#define __HANGUL_H__

/* Hangul Conversion */
#include <stdbool.h>
#include "../ucs.h"

typedef enum choseng {
  CHOSENG_K,   // ㄱ
  CHOSENG_KK,  // ㄲ
  CHOSENG_N,   // ㄴ
  CHOSENG_T,   // ㄷ
  CHOSENG_TT,  // ㄸ
  CHOSENG_R,   // ㄹ
  CHOSENG_M,   // ㅁ
  CHOSENG_P,   // ㅂ
  CHOSENG_PP,  // ㅃ
  CHOSENG_S,   // ㅅ
  CHOSENG_SS,  // ㅆ
  CHOSENG_NIL, // ㅇ
  CHOSENG_C,   // ㅈ
  CHOSENG_CC,  // ㅉ
  CHOSENG_CH,  // ㅊ
  CHOSENG_KH,  // ㅋ
  CHOSENG_TH,  // ㅌ
  CHOSENG_PH,  // ㅍ
  CHOSENG_H    // ㅎ
} choseng;

#define CHOSENG_TOTAL 19

typedef enum cungseng {
  CUNGSENG_A,   // ㅏ
  CUNGSENG_AY,  // ㅐ
  CUNGSENG_YA,  // ㅑ
  CUNGSENG_YAY, // ㅒ
  CUNGSENG_E,   // ㅓ
  CUNGSENG_EY,  // ㅔ
  CUNGSENG_YE,  // ㅕ
  CUNGSENG_YEY, // ㅖ
  CUNGSENG_O,   // ㅗ
  CUNGSENG_WA,  // ㅘ
  CUNGSENG_WAY, // ㅙ
  CUNGSENG_OE,  // ㅚ
  CUNGSENG_YO,  // ㅛ
  CUNGSENG_WU,  // ㅜ
  CUNGSENG_WO,  // ㅝ
  CUNGSENG_WEY, // ㅞ
  CUNGSENG_WI,  // ㅟ
  CUNGSENG_YU,  // ㅠ
  CUNGSENG_U,   // ㅡ
  CUNGSENG_UI,  // ㅢ
  CUNGSENG_I    // ㅣ
} cungseng;

#define CUNGSENG_TOTAL 21

typedef enum congseng {
  CONGSENG_NIL,
  CONGSENG_K,   // ㄱ
  CONGSENG_KK,  // ㄲ
  CONGSENG_KS,  // ㄳ
  CONGSENG_N,   // ㄴ
  CONGSENG_NC,  // ㄵ
  CONGSENG_NH,  // ㄶ
  CONGSENG_T,   // ㄷ
  CONGSENG_L,   // ㄹ
  CONGSENG_LK,  // ㄺ
  CONGSENG_LM,  // ㄻ
  CONGSENG_LP,  // ㄼ
  CONGSENG_LS,  // ㄽ
  CONGSENG_LTH, // ㄾ
  CONGSENG_LPH, // ㄿ
  CONGSENG_LH,  // ㅀ
  CONGSENG_M,   // ㅁ
  CONGSENG_P,   // ㅂ
  CONGSENG_PS,  // ㅄ
  CONGSENG_S,   // ㅅ
  CONGSENG_SS,  // ㅆ
  CONGSENG_NG,  // ㅇ
  CONGSENG_C,   // ㅈ
  CONGSENG_CH,  // ㅊ
  CONGSENG_KH,  // ㅋ
  CONGSENG_TH,  // ㅌ
  CONGSENG_PH,  // ㅍ
  CONGSENG_H,   // ㅎ
} congseng;

#define CONGSENG_TOTAL 28

#define HANGUL_CHOSENG_SET_TOTAL 588 // 21 * 28

typedef struct hangulChar {
  ucschar codepoint;
  bool isHangul;

  choseng syllableStart;
  cungseng vowel;
  congseng syllableFinal;
} hangulChar;

#endif
