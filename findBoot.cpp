#include <cstdio>
int main()
{
	FILE *in = fopen("plan9", "rb");
	FILE *out = fopen("boot.out", "wb");
	char prv = getc(in);
	putc(prv, out);
	int cnt = 1;
	while(!feof(in))
	{
		char cur = getc(in);
		putc(cur, out);
		++cnt;
		if (prv == char(0x55) && cur == char(0xAA) && cnt >= 512)
			break;
		prv = cur;
	}
	return 0;
}