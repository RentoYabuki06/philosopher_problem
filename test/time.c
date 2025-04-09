#include <stdio.h>
#include <sys/time.h>
#include <time.h>

/*
 * gettimeofday関数の使用例
 * 
 * gettimeofday関数は現在の時刻をマイクロ秒単位で取得できる関数です。
 * 
 * 構文:
 *   int gettimeofday(struct timeval *tv, struct timezone *tz);
 * 
 * パラメータ:
 *   - tv: 時刻情報を格納するtimeval構造体へのポインタ
 *   - tz: タイムゾーン情報を格納するtimezone構造体へのポインタ（現在は非推奨で通常NULLを指定）
 * 
 * 戻り値:
 *   - 成功時: 0
 *   - 失敗時: -1
 */

int main() {
    // timeval構造体は以下のように定義されています：
    // struct timeval {
    //     time_t      tv_sec;   // 秒
    //     suseconds_t tv_usec;  // マイクロ秒
    // };
    struct timeval tv;
    struct timezone tz;

    // gettimeofday関数を呼び出して現在時刻を取得
    if (gettimeofday(&tv, &tz) == 0) {
        // 1. UNIXエポック（1970年1月1日 00:00:00 UTC）からの経過秒数を表示
        printf("UNIXエポックからの経過秒数: %ld\n", tv.tv_sec);
        
        // 2. マイクロ秒部分を表示（0-999999の範囲）
        printf("マイクロ秒: %ld\n", tv.tv_usec);
        
        // 3. 人間が読みやすい形式に変換
        time_t now = tv.tv_sec;
        struct tm *tm_info = localtime(&now);  // ローカルタイムに変換
        char buffer[26];
        // strftimeを使用して日時を指定したフォーマットに変換
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        // マイクロ秒部分を6桁で表示（%06d）
        printf("現在時刻: %s.%06ld\n", buffer, tv.tv_usec);
    } else {
        printf("gettimeofday関数の呼び出しに失敗しました\n");
        return 1;
    }

    return 0;
}