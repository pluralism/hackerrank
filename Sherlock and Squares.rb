def squares_between(a, b)
	Math.sqrt(b).floor - Math.sqrt(a - 1).floor
end


t = gets.chomp.to_i
while t > 0 do
	s = gets.split
	a, b = s[0].to_i, s[1].to_i

	puts squares_between(a, b)
	t -= 1
end	