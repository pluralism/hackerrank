def calculate(arr)
  max_non_contiguous, max_contiguous, global_max_contiguous = arr[0], arr[0], arr[0]
  for i in 1...arr.length
    max_contiguous = [max_contiguous + arr[i], arr[i]].max
    global_max_contiguous = [global_max_contiguous, max_contiguous].max
    max_non_contiguous = [max_non_contiguous, max_non_contiguous + arr[i], arr[i]].max
  end
  return global_max_contiguous, max_non_contiguous
end

t = gets.chomp.strip.to_i

for i in 0...t
  gets.chomp.strip.to_i
  arr = gets.chomp.strip.split.map(&:to_i)
  res = calculate(arr)
  puts "#{res[0]} #{res[1]}"
end
