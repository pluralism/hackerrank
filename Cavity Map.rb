def adjacent_have_smaller_depth?(values, i, j)
	val = values[i][j]
	values[i][j + 1] < val && values[i][j - 1] < val && values[i + 1][j] < val && values[i - 1][j] < val
end

t = gets.chomp.to_i
values = []

t.times {
	tmp = []
	gets.chars.map { |i| unless i == "\n" then tmp << i.to_i end }
	values << tmp
}
copy_values = values.map do |e| e.dup end


if t > 2 then
	for i in 1...t - 1 
		for j in 1...t - 1
			if adjacent_have_smaller_depth?(copy_values, i, j) then
				values[i][j] = 'X'
			end
		end
	end
end
values.map do |e| puts e.join end