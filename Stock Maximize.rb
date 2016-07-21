def calculate(arr)
  total = 0
  while !arr.empty?
    total_tmp, current_index = 0, 0
    max_index = arr.index(arr.max)
    for i in current_index...max_index
      total_tmp += arr[i]
    end

    total += max_index * arr[max_index] - total_tmp
    arr = arr[max_index + 1..-1]
  end
  total
end


t = gets.chomp.strip.to_i
for i in 0...t
  gets.chomp
  arr = gets.chomp.strip.split.map(&:to_i)
  puts calculate(arr)
end
