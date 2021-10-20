package main

import "C"
import "net/http"
import "io/ioutil"

//export download
func download(url string) string{
	resp, err := http.Get(url)

	defer resp.Body.Close()

	html, err := ioutil.ReadAll(resp.Body)

	str := string(html)

	if(err == err){}

	return str
}


func main(){}

