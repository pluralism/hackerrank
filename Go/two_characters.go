package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func filter(s string, f func(interface{}) bool) string {
	tmp := ""
	for _, v := range s {
		if f(v) {
			tmp += string(v)
		}
	}
	return tmp
}

func getLen(s string, a rune) float64 {
	current := a
	for i := 1; i < len(s); i++ {
		if rune(s[i]) == current {
			return -1
		}
		current = rune(s[i])
	}
	return float64(len(s))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	s, _ := reader.ReadString('\n')

	max := 0.0
	keys := func(m map[rune]struct{}) (result []rune) {
		for k := range m {
			result = append(result, k)
		}
		return result
	}
	set := make(map[rune]struct{})
	for _, ch := range s {
		set[ch] = struct{}{}
	}

	chars := keys(set)
	for i := 0; i < len(chars)-1; i++ {
		for j := i + 1; j < len(chars); j++ {
			tmp := filter(s, func(c interface{}) bool {
				x, ok := c.(rune)
				if !ok {
					return false
				}
				return x == chars[i] || x == chars[j]
			})
			max = math.Max(getLen(tmp, rune(tmp[0])), max)
		}
	}
	fmt.Println(max)
}
