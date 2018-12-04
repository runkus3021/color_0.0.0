#pragma once
//キー入力関連
char keyBuf[256];
char oldkeyBuf[256];
//キーボード入力更新
void keyUpdate()
{
	for (int i = 0; i<256; i++)
	{
		oldkeyBuf[i] = keyBuf[i];
	}
	GetHitKeyStateAll(keyBuf);
}
bool pushKey(int keyNo)
{
	if (keyBuf[keyNo] == 1) return true;
	return false;
}
bool onePushKey(int keyNo)
{
	if (keyBuf[keyNo] == 1 && oldkeyBuf[keyNo] == 0) return true;
	return false;
}

