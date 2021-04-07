#include <stdio.h>
#include "../1.libft/libft.h"

// int main(int argc, char **argv)
// {
// 	int i = 0;
// 	while (i < argc)
// 	{
// 		if (ft_memcmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".cub", 4) != 0)
// 			printf("ERR\n");
// 		printf("argv[%d] = %s\n", i, argv[i]);
// 		printf("argc = %d , i = %d\n", argc, i);
// 		i++;
// 	}
// }
typedef struct _BITMAPFILEHEADER     // BMP 비트맵 파일 헤더 구조체
{
	unsigned short bfType;           // BMP 파일 매직 넘버
	unsigned int   bfSize;           // 파일 크기
	unsigned short bfReserved1;      // 예약
	unsigned short bfReserved2;      // 예약
	unsigned int   bfOffBits;        // 비트맵 데이터의 시작 위치
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
	unsigned int   biSize;           // 현재 구조체의 크기
	int            biWidth;          // 비트맵 이미지의 가로 크기
	int            biHeight;         // 비트맵 이미지의 세로 크기
	unsigned short biPlanes;         // 사용하는 색상판의 수
	unsigned short biBitCount;       // 픽셀 하나를 표현하는 비트 수
	unsigned int   biCompression;    // 압축 방식
	unsigned int   biSizeImage;      // 비트맵 이미지의 픽셀 데이터 크기
	int            biXPelsPerMeter;  // 그림의 가로 해상도(미터당 픽셀)
	int            biYPelsPerMeter;  // 그림의 세로 해상도(미터당 픽셀)
	unsigned int   biClrUsed;        // 색상 테이블에서 실제 사용되는 색상 수
	unsigned int   biClrImportant;   // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE            // 24비트 비트맵 이미지의 픽셀 구조체
{
	unsigned char rgbtBlue;          // 파랑
	unsigned char rgbtGreen;         // 초록
	unsigned char rgbtRed;           // 빨강
} RGBTRIPLE;

int main()
{
	BITMAPFILEHEADER a;
	BITMAPINFOHEADER b;
	RGBTRIPLE c;

	printf("short bfType : %lu\n", sizeof(a.bfType));
	printf("int bfSize : %lu\n", sizeof(a.bfSize));
	printf("char rgbtBlue : %lu\n", sizeof(c.rgbtBlue));
}