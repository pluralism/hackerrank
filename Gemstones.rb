def evaluate(arr)
  return 0 if arr.size == 1
  total = 0
  arr[0].each_char do |c|
    valid = true
    for i in 1...arr.size
      unless arr[i].include?(c)
        valid = false
      end
      if valid == false
        break
      end
    end
    total += 1 if valid
  end
  total
end


arr = []
N = gets.chomp.to_i
N.times do |n|
  string = gets.chomp
  arr << string.split('').to_a.uniq.join
end
puts evaluate(arr)