/*
Áö¹ÎÀÌ´Â ÀÚ½ÅÀÇ ÀúÅÃ¿¡¼­ MN°³ÀÇ ´ÜÀ§ Á¤»ç°¢ÇüÀ¸·Î ³ª´©¾îÁ® ÀÖ´Â M¡¿N Å©±âÀÇ º¸µå¸¦ Ã£¾Ò´Ù.
¾î¶² Á¤»ç°¢ÇüÀº °ËÀº»öÀ¸·Î Ä¥ÇØÁ® ÀÖ°í, ³ª¸ÓÁö´Â Èò»öÀ¸·Î Ä¥ÇØÁ® ÀÖ´Ù.
Áö¹ÎÀÌ´Â ÀÌ º¸µå¸¦ Àß¶ó¼­ 8¡¿8 Å©±âÀÇ Ã¼½ºÆÇÀ¸·Î ¸¸µé·Á°í ÇÑ´Ù.

Ã¼½ºÆÇÀº °ËÀº»ö°ú Èò»öÀÌ ¹ø°¥¾Æ¼­ Ä¥ÇØÁ® ÀÖ¾î¾ß ÇÑ´Ù.
±¸Ã¼ÀûÀ¸·Î, °¢ Ä­ÀÌ °ËÀº»ö°ú Èò»ö Áß ÇÏ³ª·Î »öÄ¥µÇ¾î ÀÖ°í, 
º¯À» °øÀ¯ÇÏ´Â µÎ °³ÀÇ »ç°¢ÇüÀº ´Ù¸¥ »öÀ¸·Î Ä¥ÇØÁ® ÀÖ¾î¾ß ÇÑ´Ù.
µû¶ó¼­ ÀÌ Á¤ÀÇ¸¦ µû¸£¸é Ã¼½ºÆÇÀ» »öÄ¥ÇÏ´Â °æ¿ì´Â µÎ °¡Áö»ÓÀÌ´Ù.
ÇÏ³ª´Â ¸Ç ¿ÞÂÊ À§ Ä­ÀÌ Èò»öÀÎ °æ¿ì, ÇÏ³ª´Â °ËÀº»öÀÎ °æ¿ìÀÌ´Ù.

º¸µå°¡ Ã¼½ºÆÇÃ³·³ Ä¥ÇØÁ® ÀÖ´Ù´Â º¸ÀåÀÌ ¾ø¾î¼­, 
Áö¹ÎÀÌ´Â 8¡¿8 Å©±âÀÇ Ã¼½ºÆÇÀ¸·Î Àß¶ó³½ ÈÄ¿¡ ¸î °³ÀÇ Á¤»ç°¢ÇüÀ» ´Ù½Ã Ä¥ÇØ¾ß°Ú´Ù°í »ý°¢Çß´Ù.
´ç¿¬È÷ 8*8 Å©±â´Â ¾Æ¹«µ¥¼­³ª °ñ¶óµµ µÈ´Ù.
Áö¹ÎÀÌ°¡ ´Ù½Ã Ä¥ÇØ¾ß ÇÏ´Â Á¤»ç°¢ÇüÀÇ ÃÖ¼Ò °³¼ö¸¦ ±¸ÇÏ´Â ÇÁ·Î±×·¥À» ÀÛ¼ºÇÏ½Ã¿À.
*/

#include <iostream>

using namespace std;

int main() {
	char chess1[8][8] = {
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W', 
	};

	char chess2[8][8] = {
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
	}; // º¸µå¿Í ºñ±³ÇÒ 2°¡Áö Á¾·ùÀÇ Ã¼½ºÆÇÀ» ÀÌÁß ¹è¿­·Î ¸¸µç´Ù


	char board[50][50] = { 0, };
	int n, m;


	cin >> n >>  m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	} // º¸µåÀÇ °¢ ´ÜÀ§ Á¤»ç°¢Çü¸¶´ÙÀÇ »ö±òÀ» ÀÔ·Â

	int min = 10000; // ´Ù½Ã Ä¥ÇÒ Á¤»ç°¢Çü °³¼öÀÇ ÃÖ¼Ú°ªÀ» ÀúÀåÇÒ º¯¼ö
	for (int k = 0; k <= n - 8; k++) {
		for (int l = 0; l <= m - 8; l++) {
			int cnt1 = 0, cnt2 = 0; // ´Ù½Ã ¯„ÇØ¾ß ÇÒ Á¤»ç°¢Çü °³¼ö¸¦ °è»êÇÒ º¯¼ö
			for (int i = k; i < 8 + k; i++) {
				for (int j = l; j < 8 + l; j++) {
					if (board[i][j] != chess1[i - k][j - l])
						cnt1++;
					if (board[i][j] != chess2[i - k][j - l])
						cnt2++;
					// º¸µå¿Í Ã¼½º1ÀÌ ´Ù¸¦ °æ¿ì cnt1À», º¸µå¿Í Ã¼½º2°¡ ´Ù¸¦ °æ¿ì cnt2¸¦ Áõ°¡½ÃÅ²´Ù
					// ÀÌ ¶§, chess1°ú chess2ÀÇ index´Â Ç×»ó 0 ~ 7·Î °íÁ¤µÇ¾î¾ß ÇÑ´Ù
				}
			}
			if (min > cnt1) {
				min = cnt1;
			}
			if (min > cnt2) {
				min = cnt2;
			} // ÃÖ¼Ú°ªÀ» ÀúÀå
		}
	} // board[0 ~ 7][0 ~ 7]À» °¢ Ã¼½ºÆÇ°ú ºñ±³ÇÏ°í, board[0 ~ 7][1 ~ 8]À» ºñ±³ÇÏ´Â ¼øÀ¸·Î,
	// ¸ðµç 8 * 8ÀÌ µÇ´Â indexµéÀ» °Ë»çÇÏ¿©, °¡Àå ÀÛÀº °ªÀ» Ãâ·Â

	cout << min << "\n";
	

}
