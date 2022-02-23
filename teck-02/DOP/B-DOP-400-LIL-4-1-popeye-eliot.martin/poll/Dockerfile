FROM python

COPY . /app
COPY requirements.txt /app

RUN pip3 install -r ./app/requirements.txt

CMD ["flask","run","--host=0.0.0.0","--port=80"]
