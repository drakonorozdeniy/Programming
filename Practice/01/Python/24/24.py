import json
j_2=[]
s=0
t=1 
with open ('in.json', 'r' ) as file :
    j= json.load(file)
for i in j :
    if i['userId']==t and i['completed']==True :
        s+=1
    elif i['userId']!=t and i['completed']==True :
        j_2.append({'userId':t, 'task_completed': s})
        s=0
        t+=1
        s+=1
j_2.append({'userId':t, 'task_completed': s})
with open('out.json' , 'w') as file :
    file.write(json.dumps(j_2,indent = 3))
