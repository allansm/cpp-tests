package main

import "C"
import "net/http"
import "io/ioutil"

//export download
func download(url *C.char) *C.char{
	resp, err := http.Get(C.GoString(url))

	if(err != nil){
		return C.CString("");
	}

	defer resp.Body.Close()

	html, err := ioutil.ReadAll(resp.Body)

	if(err != nil){
		return C.CString("");
	}

	str := string(html)

	return C.CString(str)
}

func main(){}

