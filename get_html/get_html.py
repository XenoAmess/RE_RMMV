import json

line_template = '        <script type="text/javascript" src="%s"></script>\n'
file_object = open('html_template.txt')
html_template = file_object.read()
file_object.close()


def parse(file_name):
    if(file_name.endswith(".json")):
        file_object = open(file_name)
        json_content = json.load(file_object)
        #print(json_content)
        res = [];
        for str in json_content:
            res += parse(str)
        file_object.close()
        return res 
    else:
        return [file_name]

file_list = parse("index.json")
print(file_list)

center_str = ""
for str in file_list:
    center_str += line_template % str

anser = html_template % center_str

file_object = open('index.html',"w")
file_object.write(anser)
file_object.close()
