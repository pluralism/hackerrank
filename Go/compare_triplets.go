package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	a := scanner.Text()
	scanner.Scan()
	b := scanner.Text()
	aInt := []int{}
	bInt := []int{}

	for _, i := range strings.Split(a, " ") {
		j, _ := strconv.Atoi(i)
		aInt = append(aInt, j)
	}

	for _, i := range strings.Split(b, " ") {
		j, _ := strconv.Atoi(i)
		bInt = append(bInt, j)
	}

	aCount, bCount := 0, 0
	for i := range aInt {
		if aInt[i] > bInt[i] {
			aCount++
		} else if aInt[i] < bInt[i] {
			bCount++
		}
	}

	fmt.Printf("%d %d\n", aCount, bCount)
}
