require 'descriptive_statistics'

# 理科の点数データ
science_scores = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]

# 英語の点数データ
english_scores = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

# 理科の平均点を計算
science_average = science_scores.mean
# 理科の標準偏差を計算
science_std_dev = science_scores.standard_deviation
# 理科の合計点を計算
science_sum = science_scores.sum

# 英語の平均点を計算
english_average = english_scores.mean
# 英語の標準偏差を計算
english_std_dev = english_scores.standard_deviation
# 英語の合計点を計算
english_sum = english_scores.sum

# 理科と英語のそれぞれの偏差値を計算し、配列に格納
science_deviation_values = science_scores.map { |score| ((score - science_average) / science_std_dev * 10) + 50 }
english_deviation_values = english_scores.map { |score| ((score - english_average) / english_std_dev * 10) + 50 }

# 理科と英語の点数を高い順にソート
science_scores_sorted = science_scores.sort.reverse
english_scores_sorted = english_scores.sort.reverse

# 結果を表示
puts "理科の平均点: #{science_average.round(2)}"
puts "理科の標準偏差: #{science_std_dev.round(2)}"
puts "理科の合計点: #{science_sum.round(2)}"

puts "\n英語の平均点: #{english_average.round(2)}"
puts "英語の標準偏差: #{english_std_dev.round(2)}"
puts "英語の合計点: #{english_sum.round(2)}"

puts "\n理科の偏差値:"
puts science_deviation_values.map { |deviation| deviation.round }.join(' ')

puts "\n\n英語の偏差値:"
puts english_deviation_values.map { |deviation| deviation.round }.join(' ')

puts "\n\n理科の点数（高い順）:"
puts science_scores_sorted.join(' ')

puts "\n\n英語の点数（高い順）:"
puts english_scores_sorted.join(' ')

