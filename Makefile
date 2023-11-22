# Makefile

# 컴파일러 설정
CC = g++
# 컴파일 옵션 설정
CFLAGS = -Wall -g
# 링크 옵션 설정
LFLAGS =

# 소스 코드 및 헤더 파일 경로
SRCDIR = Woojin_codes
INCDIR = -I$(SRCDIR)
# 빌드 대상 파일
TARGET = atm_app
# 컴파일할 파일 목록
SRCS = $(wildcard $(SRCDIR)/*.cpp)
# 오브젝트 파일 생성 목록
OBJS = $(SRCS:.cpp=.o)

# 목표 파일 빌드
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCDIR) -o $@ $^ $(LFLAGS)

# 각 소스 파일의 오브젝트 파일 생성
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c -o $@ $<

# clean 명령어: 생성된 파일 삭제
.PHONY: clean
clean:
	rm -f $(TARGET) $(SRCDIR)/*.o
