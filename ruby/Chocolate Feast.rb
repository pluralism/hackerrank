def chocolates_for_wrappers(chocolates, m)
	res = 0
	while chocolates / m > 0 do
		res += chocolates / m
		chocolates = (chocolates / m) + (chocolates % m)
	end
	res
end


t = gets.chomp.to_i

t.times {
	(n, c, m) = gets.split.map { |i| i.to_i }
	chocolates = n / c
	chocolates += chocolates_for_wrappers(chocolates, m)
	puts chocolates
}