package main

import "C"
import "net/http"
import "io/ioutil"

//export download
func download(url *C.char) *C.char{
	resp, err := http.Get(C.GoString(url))

	defer resp.Body.Close()

	html, err := ioutil.ReadAll(resp.Body)

	str := string(html)

	if(err == err){}

	return C.CString(str)
}

func main(){}

