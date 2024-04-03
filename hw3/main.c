#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
} lotto_record_t;

void generateNumbers(int numbers[]) {
    for (int i = 0; i < 7; ++i) {
        int num;
        do {
            num = rand() % 69 + 1;
            int found = 0;
            for (int j = 0; j < i; ++j) {
                if (numbers[j] == num) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                numbers[i] = num;
                break;
            }
        } while (1);
    }
}

void generateLottoSet(int lotto_set[][7], int set_size) {
    for (int i = 0; i < set_size; ++i) {
        generateNumbers(lotto_set[i]);
    }
}

void printLottoSet(FILE *outfile, int lotto_set[][7], int set_size) {
    for (int i = 0; i < set_size; ++i) {
        fprintf(outfile, " [%d]: %02d %02d %02d %02d %02d %02d %02d\n", i + 1, 
            lotto_set[i][0], lotto_set[i][1], lotto_set[i][2], lotto_set[i][3], 
            lotto_set[i][4], lotto_set[i][5], lotto_set[i][6]);
    }
}

int main() {
    srand(time(NULL));

    lotto_record_t record;

    FILE *record_file = fopen("record.bin", "rb");
    if (record_file == NULL) {
        record.receipt_id = 1; 
    } else {
        fseek(record_file, -sizeof(lotto_record_t), SEEK_END);
        if (fread(&record, sizeof(lotto_record_t), 1, record_file) != 1) {
            record.receipt_id = 1;
        } else {
            record.receipt_id++;
        }
        fclose(record_file);
    }

    generateLottoSet(record.lotto_set, 5);

    record.receipt_price = 50; 
    time_t now = time(NULL);
    strftime(record.receipt_time, sizeof(record.receipt_time), "%Y-%m-%d %H:%M:%S", localtime(&now));

    char filename[20];
    sprintf(filename, "lotto_record[%05d].txt", record.receipt_id);
    FILE *outfile = fopen(filename, "w");
    if (outfile == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }

    fprintf(outfile, "Receipt ID: %d\n", record.receipt_id);
    fprintf(outfile, "Receipt Price: %d\n", record.receipt_price);
    fprintf(outfile, "Receipt Time: %s\n", record.receipt_time);
    fprintf(outfile, "========= Lotto Sets =========\n");
    printLottoSet(outfile, record.lotto_set, 5);
    fprintf(outfile, "========= End of Lotto Sets =========\n");

    fclose(outfile);

    FILE *record_outfile = fopen("record.bin", "ab");
    if (record_outfile == NULL) {
        printf("無法開啟記錄檔案\n");
        return 1;
    }
    fwrite(&record, sizeof(lotto_record_t), 1, record_outfile);
    fclose(record_outfile);

    printf("已成功生成樂透記錄到 %s\n", filename);

    return 0;
}
