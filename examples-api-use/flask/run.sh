FLASK_ROOT="${FLASK_ROOT:-~/flaschen-taschen/examples-api-use/flask}"
export FLASK_APP=ftflask
export FT_HOST=displaypi.lan
export PYTHONPATH="../../api/python"
export FT_WIDTH=30
export FT_HEIGHT=22
echo $PYTHONPATH
python -m flask run --port=80 --host=displaypi.lan
