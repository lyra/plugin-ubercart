/**
 * Copyright © Lyra Network.
 * This file is part of PayZen for Ubercart. See COPYING.md for license details.
 *
 * @author    Lyra Network <https://www.lyra.com>
 * @copyright Lyra Network
 * @license   http://www.gnu.org/licenses/old-licenses/gpl-2.0.html GNU General Public License (GPL v2)
 */

(function($) {
    payzenAddOption = function payzenAddOption(first, deleteText) {
        if (first) {
            $('#uc_payzen_multi_options_btn').css('display', 'none');
            $('#uc_payzen_multi_options_table').css('display', '');
        }

        var timestamp = new Date().getTime();
        var optionLine = '<tr id="uc_payzen_multi_option_' + timestamp + '">' +
                         '    <td><input name="uc_payzen_multi_options[' + timestamp + '][label]" style="width: 150px;" type="text" /></td>' + 
                         '    <td><input name="uc_payzen_multi_options[' + timestamp + '][amount_min]" style="width: 80px;" type="text" /></td>' +
                         '    <td><input name="uc_payzen_multi_options[' + timestamp + '][amount_max]" style="width: 80px;" type="text" /></td>' +
                         '    <td><input name="uc_payzen_multi_options[' + timestamp + '][contract]" style="width: 70px;" type="text" /></td>' +
                         '    <td><input name="uc_payzen_multi_options[' + timestamp + '][count]" style="width: 70px;" type="text" /></td>' +
                         '    <td><input name="uc_payzen_multi_options[' + timestamp + '][period]" style="width: 70px;" type="text" /></td>' +
                         '    <td><input name="uc_payzen_multi_options[' + timestamp + '][first]" style="width: 70px;" type="text" /></td>' +
                         '    <td><button type="button" onclick= "payzenDeleteOption(' + timestamp + ');">' + deleteText + ' </td>' +
                         '</tr>';

        $(optionLine).insertBefore('#uc_payzen_multi_option_add');
    };

    payzenDeleteOption = function(key) {
        $('#uc_payzen_multi_option_' + key).remove();

        if ($('#uc_payzen_multi_options_table tbody tr').length === 1) {
            $('#uc_payzen_multi_options_btn').css('display', '');
            $('#uc_payzen_multi_options_table').css('display', 'none');
        }
    };
})(jQuery);