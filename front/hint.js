function createProductCodeForm(parent) {
  var form = $("<form/>");

  form.append($("<label>").text('Product Code:'));
  form.append($("<input>").attr('name', 'productCode').attr('type', 'text').attr('onfocus','$("label[name]").show()').attr('onblur','$("label[name]").hide()'));
  form.append($("<label>").attr('name', 'hint').text('The product code can be found on the label.').attr('style','display:none'));

  form.append('<br>');

  form.append($("<input>").attr('type', 'submit'));

  parent.append(form);
}