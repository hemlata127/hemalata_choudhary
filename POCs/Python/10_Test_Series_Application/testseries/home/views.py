from django.shortcuts import render, HttpResponse;

# Create your views here.
def index(request):
    #context is set of variables
    context = {'variable1':'This is sent', 'variable2':'ANother variable'};
    return render(request, 'index.html',context);
    #return HttpResponse("This is home page");

def about(request):
    #return HttpResponse("This is about page");
    return render(request, 'about.html');

def services(request):
    #return HttpResponse("This is services page");
    return render(request, 'services.html');

def contact(request):
    #return HttpResponse("This is contact page");
    return render(request, 'contact.html');