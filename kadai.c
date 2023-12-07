#include <stdio.h> 

#include <math.h> 

  

// 配列の要素数を計算するマクロ 

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0])) 

  

// 配列の合計を計算する関数 

double calculateSum(const int *arr, size_t size) { 

    double sum = 0.0; 

    for (size_t i = 0; i < size; ++i) { 

        sum += arr[i]; 

    } 

    return sum; 

} 

  

// 配列の平均を計算する関数 

double calculateAverage(const int *arr, size_t size) { 

    return calculateSum(arr, size) / size; 

} 

  

// 配列の標準偏差を計算する関数 

double calculateStandardDeviation(const int *arr, size_t size, double average) { 

    double sumOfSquaredDifferences = 0.0; 

    for (size_t i = 0; i < size; ++i) { 

        double diff = arr[i] - average; 

        sumOfSquaredDifferences += diff * diff; 

    } 

    return sqrt(sumOfSquaredDifferences / size); 

} 

  

// 配列を降順にソートする関数 

void sortDescending(int *arr, size_t size) { 

    for (size_t i = 0; i < size - 1; ++i) { 

        for (size_t j = i + 1; j < size; ++j) { 

            if (arr[i] < arr[j]) { 

                // 交換 

                int temp = arr[i]; 

                arr[i] = arr[j]; 

                arr[j] = temp; 

            } 

        } 

    } 

} 

  

int main() { 

    // 理科の点数データ 

    int science_scores[] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70}; 

  

    // 英語の点数データ 

    int english_scores[] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84}; 

  

    size_t num_students = ARRAY_SIZE(science_scores); 

  

    // 理科の平均点を計算 

    double science_average = calculateAverage(science_scores, num_students); 

    // 理科の標準偏差を計算 

    double science_std_dev = calculateStandardDeviation(science_scores, num_students, science_average); 

    // 理科の合計点を計算 

    double science_sum = calculateSum(science_scores, num_students); 

  

    // 英語の平均点を計算 

    double english_average = calculateAverage(english_scores, num_students); 

    // 英語の標準偏差を計算 

    double english_std_dev = calculateStandardDeviation(english_scores, num_students, english_average); 

    // 英語の合計点を計算 

    double english_sum = calculateSum(english_scores, num_students); 

  

    // 理科と英語のそれぞれの偏差値を計算し、配列に格納 

    int science_deviation_values[num_students]; 

    int english_deviation_values[num_students]; 

    for (size_t i = 0; i < num_students; ++i) { 

        science_deviation_values[i] = (int)((science_scores[i] - science_average) / science_std_dev * 10 + 50); 

        english_deviation_values[i] = (int)((english_scores[i] - english_average) / english_std_dev * 10 + 50); 

    } 

  

    // 理科と英語の点数を高い順に並べ替え 

    sortDescending(science_scores, num_students); 

    sortDescending(english_scores, num_students); 

  

    // 結果を表示 

    printf("理科の平均点: %.2f\n", science_average); 

    printf("理科の標準偏差: %.2f\n", science_std_dev); 

    printf("理科の合計点: %.2f\n", science_sum); 

  

    printf("\n英語の平均点: %.2f\n", english_average); 

    printf("英語の標準偏差: %.2f\n", english_std_dev); 

    printf("英語の合計点: %.2f\n", english_sum); 

  

    printf("\n理科の偏差値:\n"); 

    for (size_t i = 0; i < num_students; ++i) { 

        printf("%d ", science_deviation_values[i]); 

    } 

  

    printf("\n\n英語の偏差値:\n"); 

    for (size_t i = 0; i < num_students; ++i) { 

        printf("%d ", english_deviation_values[i]); 

    } 

  

    printf("\n\n理科の点数（高い順）:\n"); 

    for (size_t i = 0; i < num_students; ++i) { 

        printf("%d ", science_scores[i]); 

    } 

  

    printf("\n\n英語の点数（高い順）:\n"); 

    for (size_t i = 0; i < num_students; ++i) { 

        printf("%d ", english_scores[i]); 

    } 

  

    return 0; 

} 

 
